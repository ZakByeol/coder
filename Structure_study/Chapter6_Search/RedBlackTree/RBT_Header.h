#ifndef RBT_HEADER_H
#define RBT_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct RBTNode
{
    enum Color { RED, BLACK } color;
    int data;

    struct RBTNode* left;
    struct RBTNode* right;
    struct RBTNode* parent;
} RBTNode;

extern RBTNode* NILL; // 모든 파일이 공유하는 NIL 노드 (정의는 RBT_Functions.c에 한 번만)

// treeRoot : 트리 전체의 루트 변수의 주소 (루트가 바뀌면 갱신됨)
// exisRoot : 회전으로 내려갈 노드
void RBT_RotateRight(RBTNode** treeRoot, RBTNode* exisRoot);
void RBT_RotateLeft(RBTNode** treeRoot, RBTNode* exisRoot);

// 삽입 : InsertHelper(BST 위치 확립) -> RebuildAfterInsert(RB 규칙 복구)
void RBT_InsertHelper(RBTNode** treeRoot, RBTNode* NewNode);
void RBT_RebuildAfterInsert(RBTNode** treeRoot, RBTNode* NewNode);
void RBT_InsertNode(RBTNode** treeRoot, RBTNode* NewNode);

#endif
