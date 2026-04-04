#include "RBT_Header.h"

extern RBTNode* NILL; // 전역 변수로 NIL 노드 선언

void RBT_RotateRight(RBTNode** root, RBTNode* parent) // root : 트리 전체의 루트 노드, parent : 회전할 노드
{
    if(parent == NILL || parent->left == NILL) // exception handling
        return;

    // ⓐ RightSubTree, Root의 좌/우 위치 수정
    RBTNode* RotationNode = parent->left; // 회전할 대상을 Root를 활용하여 지정
    parent->left = RotationNode->right; // "RightSubTree"가 "Root"의 왼쪽 자식이 된다.
    RotationNode->right = parent; // "Root"가 "RightSubTree"의 오른쪽 자식이 된다.
    

    // ⓑ 노드를 교체하면서 생긴 수정소요 중, 부모 포인터에 관한 부분을 수정함
    if (RotationNode->right != NILL) // RightSubTree의 부모 수정
        RotationNode->right->parent = parent;

    RotationNode->parent = parent->parent; // 회전노드(RotationNode)의 부모 수정
    parent->parent = RotationNode;

    // ⓒ Parent노드의 부모노드's 좌/우 자식노드 포인터 수정
    if (parent->parent == NULL)
    {
        *root = RotationNode; // 회전노드가 트리의 루트 노드가 된다.
    }
    else
    {
        if (parent == parent->parent->left) // Parent노드가 부모노드의 왼쪽 자식인 경우
            parent->parent->left = RotationNode;
        else // Parent노드가 부모노드의 오른쪽 자식인 경우
            parent->parent->right = RotationNode;
    }
    

}