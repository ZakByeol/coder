#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData)
{
    BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));

    if (NewNode == NULL)
    {
        printf("메모리 할당 실패\n");
        return NULL;
    }

    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
    free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
    if (Tree == NULL)
        return;

    if (Tree->Right != NULL)
        BST_DestroyTree(Tree->Right);

    if (Tree->Left != NULL)
        BST_DestroyTree(Tree->Left);

    Tree->Left = NULL;
    Tree->Right = NULL;

    BST_DestroyNode(Tree);
}



// 이진탐색을 활용한 이진트리 탐색함수 : 함수재귀를 통한 이진탐색, 또 반환값은 BSTNODE* 형태로 한다.
BSTNode*  BST_SearchNode( BSTNode* Tree, ElementType Target )
{

    if (Tree == NULL)
        return NULL; // C에는 nullptr 가 없단다...
    

    if (Target > Tree->Data)
        BST_SearchNode(Tree->Right, Target);
    else if (Target < Tree->Data)
        BST_SearchNode(Tree->Left, Target);
    else
        return Tree;
}

// 최솟값 노드를 찾는 함수 : 반복되는 왼쪽노드 탐색으로 특정 트리의 최솟값을 찾는다.
BSTNode*  BST_SearchMinNode( BSTNode* Tree )
{
    if(Tree->Left == NULL)
        return Tree;

    if (Tree->Left != NULL)
        BST_SearchMinNode(Tree->Left);
    
}

// 이진트리 삽입 함수(트리 루트노드, 삽입 노드)
// ⓐ 삽입 노드와 루트 노드의 값을 비교하며 이진탐색을 행한다.
// ⓑ 이진탐색 후 해당 노드의 자식노드가 존재하면, 재귀를 활용한 반복
// ⓒ 존재하지 않으면, 해당 방향의 자식노드를 삽입노드로 할당한다.
void      BST_InsertNode( BSTNode* Tree, BSTNode *Child )
{
    if (Child->Data > Tree->Data)
    {
        if (Tree->Right == NULL)
            Tree->Right = Child;
        else
            BST_InsertNode(Tree->Right, Child);
    }
    else
    {
        if (Tree->Left == NULL)
            Tree->Left = Child;
        else
            BST_InsertNode(Tree->Left, Child);
    }
    
}


// 이진트리 노드 삭제 함수
// ⓐ 먼저 탐색 함수를 활용하여 삭제하고자 하는 노드를 찾는다.
// ⓑ
BSTNode*  BST_RemoveNode( BSTNode* Tree,BSTNode* Parent, ElementType Target )
{

};

void      BST_InorderPrintTree( BSTNode* Node );