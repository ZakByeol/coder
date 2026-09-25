#include "RBT_Header.h"
#include <limits.h>
#include <sys/stat.h>

// 빌드 : gcc -Wall -Wextra RBT_Functions.c RBT_Test.c -o rbt_test
// 실행 : ./rbt_test              -> 대화형 (숫자 입력 시 삽입, r: 초기화, q: 종료)
//        ./rbt_test 10 20 30 ... -> 인자로 준 값을 순서대로 삽입
//
// 삽입할 때마다 rbt_view/current.svg 가 갱신됨
//   -> VSCode에서 rbt_view/current.svg 를 열고 오른쪽 분할(Split Editor)로 띄워두면
//      삽입할 때마다 그림이 자동으로 바뀜
//   -> 각 단계 그림은 rbt_view/step_NN.svg 로도 남음

#define VIEW_DIR   "rbt_view"
#define MAX_NODES  1024
#define MAX_DEPTH  64
#define MAX_DETAIL 8

// ───────────── RB 규칙 검사 결과 ─────────────
typedef struct
{
    int rootBlack;        // 규칙 2 : 루트는 검은색
    int nilBlack;         // 규칙 3 : NIL(리프)은 검은색
    int noRedRed;         // 규칙 4 : 빨간 노드의 자식은 모두 검은색
    int sameBlackHeight;  // 규칙 5 : 모든 경로의 검은 노드 수가 같음
    int bstOrder;         // 구조 : BST 대소관계
    int parentLinks;      // 구조 : child->parent 양방향 링크
    int noCycle;          // 구조 : 순환/깊이 폭주 없음
    int blackHeight;

    char detail[MAX_DETAIL][128];
    int detailCnt;

    RBTNode* bad[MAX_NODES]; // 위반 위치로 표시할 노드
    int badCnt;
} CheckResult;

static void AddBad(CheckResult* r, RBTNode* node)
{
    for (int i = 0; i < r->badCnt; i++) if (r->bad[i] == node) return;
    if (r->badCnt < MAX_NODES) r->bad[r->badCnt++] = node;
}

static void AddDetail(CheckResult* r, const char* msg, int data)
{
    if (r->detailCnt < MAX_DETAIL)
        snprintf(r->detail[r->detailCnt++], 128, msg, data);
}

static int IsBad(const CheckResult* r, RBTNode* node)
{
    for (int i = 0; i < r->badCnt; i++) if (r->bad[i] == node) return 1;
    return 0;
}

// node 서브트리의 black-height 반환 (NIL 제외), 문제가 있으면 -1
// lo <= data <= hi 를 만족해야 함 (같은 값은 회전으로 왼쪽에도 갈 수 있으므로 양쪽 모두 허용)
static int CheckNode(RBTNode* node, int depth, long lo, long hi, CheckResult* r)
{
    if (node == NILL) return 0;
    if (depth > MAX_DEPTH)
    {
        if (r->noCycle) AddDetail(r, "깊이 %d 초과: 순환 링크 의심", MAX_DEPTH);
        r->noCycle = 0;
        return -1;
    }

    if (node->data < lo || node->data > hi)
    {
        r->bstOrder = 0;
        AddBad(r, node);
        AddDetail(r, "BST 순서 위반: %d", node->data);
    }

    if (node->color == RED && (node->left->color == RED || node->right->color == RED))
    {
        r->noRedRed = 0;
        AddBad(r, node);
        AddDetail(r, "Red-Red 연속: %d 와 그 자식", node->data);
    }

    if ((node->left != NILL && node->left->parent != node) ||
        (node->right != NILL && node->right->parent != node))
    {
        r->parentLinks = 0;
        AddBad(r, node);
        AddDetail(r, "parent 링크 불일치: %d 의 자식", node->data);
    }

    int lh = CheckNode(node->left, depth + 1, lo, node->data, r);
    int rh = CheckNode(node->right, depth + 1, node->data, hi, r);
    if (lh < 0 || rh < 0) return -1;

    if (lh != rh)
    {
        r->sameBlackHeight = 0;
        AddBad(r, node);
        AddDetail(r, "black-height 불일치: %d 의 좌/우", node->data);
        return -1;
    }
    return lh + (node->color == BLACK ? 1 : 0);
}

static CheckResult CheckTree(RBTNode* root)
{
    CheckResult r;
    memset(&r, 0, sizeof(r));
    r.rootBlack = r.nilBlack = r.noRedRed = r.sameBlackHeight = 1;
    r.bstOrder = r.parentLinks = r.noCycle = 1;

    if (NILL->color != BLACK)
    {
        r.nilBlack = 0;
        AddDetail(&r, "NIL 센티넬이 검은색이 아님%.0d", 0);
    }
    if (root != NILL && root->color != BLACK)
    {
        r.rootBlack = 0;
        AddBad(&r, root);
        AddDetail(&r, "루트 %d 가 빨간색", root->data);
    }
    if (root != NILL && root->parent != NILL)
    {
        r.parentLinks = 0;
        AddBad(&r, root);
        AddDetail(&r, "루트 %d 의 parent 가 NILL 이 아님", root->data);
    }

    r.blackHeight = CheckNode(root, 0, LONG_MIN, LONG_MAX, &r);
    return r;
}

static int AllRulesOK(const CheckResult* r)
{
    return r->rootBlack && r->nilBlack && r->noRedRed && r->sameBlackHeight &&
           r->bstOrder && r->parentLinks && r->noCycle;
}

// ───────────── 노드 생성 / 해제 ─────────────
static void InitNILL(void)
{
    NILL = (RBTNode*)malloc(sizeof(RBTNode));
    NILL->color = BLACK;
    NILL->data = 0;
    NILL->left = NILL->right = NILL->parent = NILL;
}

static RBTNode* CreateNode(int data)
{
    RBTNode* node = (RBTNode*)malloc(sizeof(RBTNode));
    node->color = RED;
    node->data = data;
    node->left = node->right = node->parent = NILL;
    return node;
}

static void DestroyTree(RBTNode* node, int depth)
{
    if (node == NILL || depth > MAX_DEPTH) return; // 순환이 있으면 해제 포기 (테스트용)
    DestroyTree(node->left, depth + 1);
    DestroyTree(node->right, depth + 1);
    free(node);
}

// ───────────── 레이아웃 (x = in-order 순번, y = 깊이) ─────────────
typedef struct { RBTNode* node; int x, y; } NodePos;

static NodePos g_pos[MAX_NODES];
static int g_posCnt;
static int g_order;

static void Layout(RBTNode* node, int depth)
{
    if (node == NILL || depth > MAX_DEPTH || g_posCnt >= MAX_NODES) return;
    Layout(node->left, depth + 1);
    g_pos[g_posCnt].node = node;
    g_pos[g_posCnt].x = g_order++;
    g_pos[g_posCnt].y = depth;
    g_posCnt++;
    Layout(node->right, depth + 1);
}

static NodePos* FindPos(RBTNode* node)
{
    for (int i = 0; i < g_posCnt; i++) if (g_pos[i].node == node) return &g_pos[i];
    return NULL;
}

// ───────────── SVG 출력 ─────────────
#define GAP_X   52
#define GAP_Y   72
#define MARGIN  40
#define RADIUS  18
#define PANEL_W 400

#define COL_RED   "#d83b3b"
#define COL_BLACK "#262626"
#define COL_OK    "#1f8a4c"
#define COL_FAIL  "#d83b3b"
#define COL_WARN  "#f28c1b"
#define COL_NEW   "#2f6fde"

static void SvgRule(FILE* f, int y, int ok, const char* text)
{
    fprintf(f, "<text x=\"20\" y=\"%d\" font-size=\"15\" fill=\"%s\" font-weight=\"bold\">%s</text>\n",
            y, ok ? COL_OK : COL_FAIL, ok ? "✔" : "✘");
    fprintf(f, "<text x=\"42\" y=\"%d\" font-size=\"14\" fill=\"#222\">%s</text>\n", y, text);
}

static void WriteSVG(const char* path, RBTNode* root, const CheckResult* r,
                     RBTNode* lastNode, const int* history, int histCnt)
{
    FILE* f = fopen(path, "w");
    if (!f) { printf("  (SVG 파일을 열 수 없음: %s)\n", path); return; }

    g_posCnt = 0; g_order = 0;
    Layout(root, 0);

    int maxDepth = 0;
    for (int i = 0; i < g_posCnt; i++) if (g_pos[i].y > maxDepth) maxDepth = g_pos[i].y;

    int treeW = MARGIN * 2 + (g_posCnt > 0 ? (g_posCnt - 1) * GAP_X : 0);
    if (treeW < 320) treeW = 320;
    int treeH = MARGIN * 2 + 40 + (maxDepth + 1) * GAP_Y;
    int panelH = 330 + r->detailCnt * 20 + 60;
    int width = treeW + PANEL_W;
    int height = treeH > panelH ? treeH : panelH;
    int offsetX = (treeW - (MARGIN * 2 + (g_posCnt > 0 ? (g_posCnt - 1) * GAP_X : 0))) / 2;

    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" "
               "viewBox=\"0 0 %d %d\" font-family=\"sans-serif\">\n", width, height, width, height);
    fprintf(f, "<rect width=\"100%%\" height=\"100%%\" fill=\"#ffffff\"/>\n");

    #define PX(p) (offsetX + MARGIN + (p)->x * GAP_X)
    #define PY(p) (MARGIN + 30 + (p)->y * GAP_Y)

    // 간선 + NIL 리프
    for (int i = 0; i < g_posCnt; i++)
    {
        NodePos* p = &g_pos[i];
        RBTNode* kids[2] = { p->node->left, p->node->right };
        for (int k = 0; k < 2; k++)
        {
            if (kids[k] != NILL)
            {
                NodePos* c = FindPos(kids[k]);
                if (c) fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#888\" stroke-width=\"2\"/>\n",
                               PX(p), PY(p), PX(c), PY(c));
            }
            else
            {
                int nx = PX(p) + (k == 0 ? -14 : 14), ny = PY(p) + 36;
                fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#ccc\" stroke-width=\"1\"/>\n",
                        PX(p), PY(p), nx, ny);
                fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"10\" height=\"8\" fill=\"%s\"/>\n",
                        nx - 5, ny - 4, NILL->color == BLACK ? COL_BLACK : COL_RED);
            }
        }
    }

    // 노드
    for (int i = 0; i < g_posCnt; i++)
    {
        NodePos* p = &g_pos[i];
        if (IsBad(r, p->node))
            fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"none\" stroke=\"%s\" stroke-width=\"4\"/>\n",
                    PX(p), PY(p), RADIUS + 6, COL_WARN);
        if (p->node == lastNode)
            fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"none\" stroke=\"%s\" stroke-width=\"2\" stroke-dasharray=\"4 3\"/>\n",
                    PX(p), PY(p), RADIUS + 11, COL_NEW);
        fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\"/>\n",
                PX(p), PY(p), RADIUS, p->node->color == RED ? COL_RED : COL_BLACK);
        fprintf(f, "<text x=\"%d\" y=\"%d\" font-size=\"13\" fill=\"#fff\" text-anchor=\"middle\" "
                   "dominant-baseline=\"central\" font-weight=\"bold\">%d</text>\n",
                PX(p), PY(p), p->node->data);
    }
    if (g_posCnt == 0)
        fprintf(f, "<text x=\"%d\" y=\"%d\" font-size=\"16\" fill=\"#888\" text-anchor=\"middle\">(빈 트리)</text>\n",
                treeW / 2, MARGIN + 40);

    // 오른쪽 규칙 패널
    int ok = AllRulesOK(r);
    fprintf(f, "<g transform=\"translate(%d,0)\">\n", treeW);
    fprintf(f, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"#f5f6f8\"/>\n", PANEL_W, height);
    fprintf(f, "<text x=\"20\" y=\"36\" font-size=\"18\" font-weight=\"bold\" fill=\"#222\">Red-Black Tree 규칙 검사</text>\n");

    if (lastNode)
        fprintf(f, "<text x=\"20\" y=\"62\" font-size=\"14\" fill=\"%s\">방금 삽입: %d (파란 점선)</text>\n",
                COL_NEW, lastNode->data);

    fprintf(f, "<rect x=\"20\" y=\"78\" width=\"%d\" height=\"34\" rx=\"6\" fill=\"%s\"/>\n",
            PANEL_W - 40, ok ? COL_OK : COL_FAIL);
    fprintf(f, "<text x=\"%d\" y=\"100\" font-size=\"15\" fill=\"#fff\" font-weight=\"bold\" text-anchor=\"middle\">%s</text>\n",
            PANEL_W / 2, ok ? "✔ 모든 규칙 만족" : "✘ 규칙 위반 발생");

    int y = 142;
    SvgRule(f, y, 1, "1. 모든 노드는 빨강 또는 검정"); y += 26;
    SvgRule(f, y, r->rootBlack, "2. 루트는 검은색"); y += 26;
    SvgRule(f, y, r->nilBlack, "3. NIL(리프)은 검은색"); y += 26;
    SvgRule(f, y, r->noRedRed, "4. 빨간 노드의 자식은 검은색"); y += 26;
    char bhText[96];
    if (r->sameBlackHeight && r->blackHeight >= 0)
        snprintf(bhText, sizeof(bhText), "5. 모든 경로의 black-height 동일 (bh=%d)", r->blackHeight);
    else
        snprintf(bhText, sizeof(bhText), "5. 모든 경로의 black-height 동일");
    SvgRule(f, y, r->sameBlackHeight, bhText); y += 34;

    fprintf(f, "<text x=\"20\" y=\"%d\" font-size=\"13\" fill=\"#666\">구조 검사</text>\n", y); y += 24;
    SvgRule(f, y, r->bstOrder, "BST 대소관계 유지"); y += 26;
    SvgRule(f, y, r->parentLinks && r->noCycle, "child ↔ parent 링크 일치"); y += 34;

    if (r->detailCnt > 0)
    {
        fprintf(f, "<text x=\"20\" y=\"%d\" font-size=\"13\" fill=\"%s\">위반 위치 (주황 테두리)</text>\n", y, COL_WARN);
        y += 22;
        for (int i = 0; i < r->detailCnt; i++, y += 20)
            fprintf(f, "<text x=\"28\" y=\"%d\" font-size=\"13\" fill=\"#222\">· %s</text>\n", y, r->detail[i]);
        y += 10;
    }

    fprintf(f, "<text x=\"20\" y=\"%d\" font-size=\"13\" fill=\"#666\">삽입 순서</text>\n", y); y += 20;
    fprintf(f, "<text x=\"20\" y=\"%d\" font-size=\"13\" fill=\"#222\">", y);
    int start = histCnt > 16 ? histCnt - 16 : 0;
    if (start > 0) fprintf(f, "… ");
    for (int i = start; i < histCnt; i++) fprintf(f, "%d%s", history[i], i + 1 < histCnt ? " → " : "");
    fprintf(f, "</text>\n</g>\n</svg>\n");

    #undef PX
    #undef PY
    fclose(f);
}

// ───────────── 터미널 출력 ─────────────
static void PrintTree(RBTNode* node, int depth)
{
    if (node == NILL || depth > MAX_DEPTH) return;
    PrintTree(node->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("       ");
    if (node->color == RED) printf("\033[1;31m%d(R)\033[0m\n", node->data);
    else                    printf("\033[1m%d(B)\033[0m\n", node->data);
    PrintTree(node->left, depth + 1);
}

static void PrintCheck(const CheckResult* r)
{
    printf("  %s\n", AllRulesOK(r) ? "\033[1;32m✔ 모든 규칙 만족\033[0m" : "\033[1;31m✘ 규칙 위반 발생\033[0m");
    for (int i = 0; i < r->detailCnt; i++) printf("    · %s\n", r->detail[i]);
}

// ───────────── 삽입 + 시각화 ─────────────
static int g_history[4096];
static int g_histCnt;
static int g_step;

static void InsertAndShow(RBTNode** root, int value)
{
    RBTNode* node = CreateNode(value);
    RBT_InsertNode(root, node);

    if (g_histCnt < 4096) g_history[g_histCnt++] = value;
    g_step++;

    CheckResult r = CheckTree(*root);

    printf("\n── step %d : %d 삽입 ──\n", g_step, value);
    PrintTree(*root, 1);
    PrintCheck(&r);

    char path[64];
    snprintf(path, sizeof(path), VIEW_DIR "/step_%02d.svg", g_step);
    WriteSVG(path, *root, &r, node, g_history, g_histCnt);
    WriteSVG(VIEW_DIR "/current.svg", *root, &r, node, g_history, g_histCnt);
}

static void ResetView(RBTNode** root)
{
    DestroyTree(*root, 0);
    *root = NILL;
    g_histCnt = 0;
    g_step = 0;
    CheckResult r = CheckTree(*root);
    WriteSVG(VIEW_DIR "/current.svg", *root, &r, NULL, g_history, 0);
}

int main(int argc, char* argv[])
{
    RBTNode* root;

    InitNILL();
    root = NILL;
    mkdir(VIEW_DIR, 0755);
    ResetView(&root);

    printf("그림: %s/current.svg 를 VSCode에서 열어 옆에 띄워두세요.\n", VIEW_DIR);

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++) InsertAndShow(&root, atoi(argv[i]));
    }
    else
    {
        char buf[64];
        printf("삽입할 값을 입력하세요 (여러 개 가능 / r: 초기화 / q: 종료)\n");
        while (printf("> "), fflush(stdout), scanf("%63s", buf) == 1)
        {
            if (strcmp(buf, "q") == 0) break;
            if (strcmp(buf, "r") == 0) { ResetView(&root); printf("트리를 초기화했습니다.\n"); continue; }

            char* end;
            long v = strtol(buf, &end, 10);
            if (*end != '\0') { printf("숫자, r, q 중 하나를 입력하세요.\n"); continue; }
            InsertAndShow(&root, (int)v);
        }
    }

    DestroyTree(root, 0);
    free(NILL);
    return 0;
}
