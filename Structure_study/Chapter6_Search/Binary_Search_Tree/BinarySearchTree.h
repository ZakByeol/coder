#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode // BST에 사용될 노드 : LeftChild, RightChild를 가르키는 노드 포인터와 해당 노드에 할당된 데이터가 선언됨
{
    struct tagBSTNode* Left;
    struct tagBSTNode* Right;

    ElementType Data;
} BSTNode;

BSTNode*  BST_CreateNode( ElementType NewData );
void      BST_DestroyNode( BSTNode* Node );
void      BST_DestroyTree( BSTNode* Tree );

BSTNode*  BST_SearchNode( BSTNode* Tree, ElementType Target );
BSTNode*  BST_SearchMinNode( BSTNode* Tree );
void      BST_InsertNode( BSTNode* Tree, BSTNode *Child );
BSTNode*  BST_RemoveNode( BSTNode* Tree,BSTNode* Parent, ElementType Target );
void      BST_InorderPrintTree( BSTNode* Node );

#endif 
