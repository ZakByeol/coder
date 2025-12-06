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

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
    if (Tree == NULL)
        return NULL;

    if (Tree->Data == Target)
        return Tree;
    else if (Tree->Data > Target)
        return BST_SearchNode(Tree->Left, Target);
    else
        return BST_SearchNode(Tree->Right, Target);
}

// 계속 왼쪽 자식 노드를 탐색하여 최소 값을 갖는 노드를 탐색한다.
BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
    if (Tree == NULL)
        return NULL;

    if (Tree->Left == NULL)
        return Tree;
    else
        return BST_SearchMinNode(Tree->Left);
}

// 새 노드의 값이 트리의 값보다 큰 경우/작은 경우를 판단하고, 결과에 따라
// 자식노드가 비어있으면 해당 노드에 삽입, 혹은 존재할시, 함수를 재귀한다.
void BST_InsertNode(BSTNode* Tree, BSTNode* NewNode)
{
    if (Tree->Data < NewNode->Data)
    {
        if (Tree->Right == NULL)
            Tree->Right = NewNode;
        else
            BST_InsertNode(Tree->Right, NewNode);
    }
    else if (Tree->Data > NewNode->Data)
    {
        if (Tree->Left == NULL)
            Tree->Left = NewNode;
        else
            BST_InsertNode(Tree->Left, NewNode);
    }
}

// 이진탐색트리 노드 제거 //
// 이진탐색트리의 대상 구조체 포인터, 부모노드 구조체 포인터, 목표값  
BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, ElementType Target)
{
    BSTNode* Removed = NULL;

    if (Tree == NULL)
        return NULL;

    // 목표값까지 도달할 수 있도록 조건을 달아 둠
    if (Tree->Data > Target)
        Removed = BST_RemoveNode(Tree->Left, Tree, Target);
    else if (Tree->Data < Target)
        Removed = BST_RemoveNode(Tree->Right, Tree, Target);

    // 위 조건들을 계속 재귀를 통해 실행하여 목표값을 찾은 경우
    else
    {
        Removed = Tree;

        // 목표값의 노드가 잎 노드인 경우 바로 삭제
        if (Tree->Left == NULL && Tree->Right == NULL)
        {
            if (Parent->Left == Tree)
                Parent->Left = NULL;
            else
                Parent->Right = NULL;
        }
        // 목표값의 노드가 부모 노드인 경우
        else
        {
            //  자식이 양쪽 다 있는 경우
            if (Tree->Left != NULL && Tree->Right != NULL)
            {
                //  최소값 노드를 찾아 제거한 뒤 현재의 노드에 위치시킨다.
                BSTNode* MinNode = BST_SearchMinNode(Tree->Right);

                // 제거하는 노드를 정렬&제거 처리와 함께 밑에 있는 자식노드들 또한 정렬&제거
                MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data); 
                Tree->Data = MinNode->Data;
            }
            else
            {
                //  자식이 하나만 있는 경우
                BSTNode* Temp = NULL;
                if (Tree->Left != NULL)
                    Temp = Tree->Left;
                else
                    Temp = Tree->Right;

                if (Parent->Left == Tree)
                    Parent->Left = Temp;
                else
                    Parent->Right = Temp;
            }
        }
    }

    return Removed;
}

void BST_InorderPrintTree(BSTNode *Node)
{
    if (Node == NULL)
        return;

    //  왼쪽 하위 트리 출력
    BST_InorderPrintTree(Node->Left);

    //  루트 노드 출력
    printf("%d ", Node->Data);

    //  오른쪽 하위 트리 출력
    BST_InorderPrintTree(Node->Right);
}
