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
// ⓑ TargetNode 의 자식노드의 유무 및 갯수에 따른 분기점을 만든다
//      왼쪽&오른쪽 자식이 없다 -> 그냥 삭제
//      자식이 하나 있다. -> 부모노드와 연결한다.
//      자식노드가 2개 있다  
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
