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
