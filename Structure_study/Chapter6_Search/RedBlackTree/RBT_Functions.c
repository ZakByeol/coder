#include "RBT_Header.h"

RBTNode* NILL = NULL; // NIL 노드 정의 (선언은 RBT_Header.h의 extern)

// treeRoot : 트리 전체의 루트 변수의 주소, exisRoot : 회전으로 내려갈 노드 (왼쪽 자식이 올라옴)
void RBT_RotateRight(RBTNode** treeRoot, RBTNode* exisRoot)
{
    RBTNode* Grand_Node = exisRoot->parent;
    RBTNode* newRoot = exisRoot->left;
    RBTNode* PRST = newRoot->right;

    // ⓐ GP와 newRoot간의 수정
    // GP가 없으면 트리 루트 갱신, 있으면 exisRoot가 있던 자리에 newRoot 연결
    if (Grand_Node == NILL) *treeRoot = newRoot;
    else if (Grand_Node->right == exisRoot) Grand_Node->right = newRoot;
    else Grand_Node->left = newRoot;
    newRoot->parent = Grand_Node;

    // ⓑ 우회전 필수 로직 - exisRoot와 newRoot의 이동 / newRoot의 RST(Right SubTree) 이동
    exisRoot->parent = newRoot;
    exisRoot->left = PRST;
    if (PRST != NILL) PRST->parent = exisRoot;

    // ⓒ newRoot의 오른쪽 자식노드를 exisRoot로 초기화
    newRoot->right = exisRoot;
}

// treeRoot : 트리 전체의 루트 변수의 주소, exisRoot : 회전으로 내려갈 노드 (오른쪽 자식이 올라옴)
void RBT_RotateLeft(RBTNode** treeRoot, RBTNode* exisRoot)
{
    RBTNode* Grand_Node = exisRoot->parent;
    RBTNode* newRoot = exisRoot->right;
    RBTNode* PLST = newRoot->left;

    // ⓐ GP와 newRoot간의 수정
    // GP가 없으면 트리 루트 갱신, 있으면 exisRoot가 있던 자리에 newRoot 연결
    if (Grand_Node == NILL) *treeRoot = newRoot;
    else if (Grand_Node->right == exisRoot) Grand_Node->right = newRoot;
    else Grand_Node->left = newRoot;
    newRoot->parent = Grand_Node;

    // ⓑ 좌회전 필수 로직 - exisRoot와 newRoot의 이동 / newRoot의 LST(Left SubTree) 이동
    exisRoot->parent = newRoot;
    exisRoot->right = PLST;
    if (PLST != NILL) PLST->parent = exisRoot;

    // ⓒ newRoot의 왼쪽 자식노드를 exisRoot로 초기화
    newRoot->left = exisRoot;
}

// ____________구분선______________


void RBT_InsertHelper(RBTNode** treeRoot, RBTNode* NewNode)
{
    // 새로운 노드의 삽입될 위치를 BST를 통해 확립 및 삽입을 한다.
    RBTNode* Parent_Node = NILL;
    RBTNode* Cur_Node = *treeRoot;

    // ⓐ 루트부터 내려가며 삽입될 위치(NILL)와 그 부모를 찾음 [이분탐색](같은 값은 오른쪽으로)
    while (Cur_Node != NILL)
    {
        Parent_Node = Cur_Node;
        if (NewNode->data < Cur_Node->data) Cur_Node = Cur_Node->left;
        else Cur_Node = Cur_Node->right;
    }

    // ⓑ 새 노드는 항상 리프이므로 자식은 NILL, 부모는 찾은 위치의 부모
    NewNode->left = NILL;
    NewNode->right = NILL;
    NewNode->parent = Parent_Node;

    // ⓒ 부모가 없으면 빈 트리 -> 트리 루트 갱신, 있으면 대소관계에 따라 연결
    if (Parent_Node == NILL) *treeRoot = NewNode;
    else if (NewNode->data < Parent_Node->data) Parent_Node->left = NewNode;
    else Parent_Node->right = NewNode;
}


void RBT_RebuildAfterInsert(RBTNode** treeRoot, RBTNode* NewNode)
{
    RBTNode* parentNode;
    RBTNode* gramdNode;
    RBTNode* uncleNode;

    RBTNode* currentNode = NewNode;

    while (parentNode = currentNode->parent, parentNode->color == RED && currentNode != *treeRoot)
    {
        // if(parentNode->parent != NILL)
        gramdNode = parentNode->parent; // 이 조건문 필요없을 것 같은데?

        if (parentNode == gramdNode->left) // P가 GP의 왼쪽 자식일때, U 포인터를 할당하기 위함
        {
            uncleNode = gramdNode->right;
            if (uncleNode->color == RED) // ⓐ U가 빨간색일때
            {
                parentNode->color = BLACK;
                uncleNode->color = BLACK;
                gramdNode->color = RED;

                currentNode = gramdNode;
                continue;
            }
            // ⓑ U가 검은색이고, N이 P의 오른쪽 자식일 경우
            else if (uncleNode->color == BLACK && currentNode == parentNode->right)
            {
                RBT_RotateLeft(&parentNode, parentNode);
                currentNode = parentNode;
                parentNode = currentNode->parent;
            }
            // 경우 ② 충족시 브라켓 탈출 후 아래 코드가 실행됨 (자동으로 경우 ③으로 이동됨)
            parentNode->color = BLACK;
            gramdNode->color = RED;
            
            RBT_RotateRight(&gramdNode, gramdNode);
        }
        else // P가 GP의 오른쪽 자식일때
        {
            uncleNode = gramdNode->left;
            if (uncleNode->color == RED) // ⓐ U가 빨간색일때
            {
                parentNode->color = BLACK;
                uncleNode->color = BLACK;
                gramdNode->color = RED;

                currentNode = gramdNode;
                continue;
            }
            // ⓑ U가 검은색이고, N이 P의 왼쪽 자식일 경우 : 우회전
            else if (uncleNode->color == BLACK && currentNode == parentNode->left)
            {
                RBT_RotateRight(&parentNode, parentNode);
                currentNode = parentNode;
                parentNode = currentNode->parent;
            }
            // 경우 ② 충족시 브라켓 탈출 후 아래 코드가 실행됨 (자동으로 경우 ③으로 이동됨)
            parentNode->color = BLACK;
            gramdNode->color = RED;

            RBT_RotateLeft(&gramdNode, gramdNode);
        }
        
        
    }
    
    (*treeRoot)->color = BLACK;
    
    
}

void RBT_InsertNode(RBTNode** treeRoot, RBTNode* NewNode)
{
    RBT_InsertHelper(treeRoot, NewNode);

    NewNode->left = NILL;
    NewNode->right = NILL;
    NewNode->color = RED;

    RBT_RebuildAfterInsert(treeRoot, NewNode);
}
