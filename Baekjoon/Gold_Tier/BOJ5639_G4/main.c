#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode {
	int key;
	struct Treenode* left;
	struct Treenode* right;
}Treenode;

// 노드 선언 및 초기화
Treenode* new_node(int item)
{
	Treenode* tmp = (Treenode*)malloc(sizeof(Treenode));
	tmp->key = item;
	tmp->left = NULL;
	tmp->right = NULL;
	
	return tmp;
}

/* 이진 트리를 전위 순회 형태로 입력을 받는다! */
// 노드 삽입, 재귀함수를 사용한 노드 탐색
Treenode* insert_node(Treenode* node, int key)
{
	if (node == NULL)
	{
		return new_node(key);
	}

	else if (key < node->key)
	{
		node->left = insert_node(node->left, key);
	}

	else if (key > node->key)
	{
		node->right = insert_node(node->right, key);
	}

	return node;
}

// 주어진 트리를 후위순회로 출력 및 동적해제
void postorder(Treenode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->key);
		free(root);
	}
}

int main(void)
{
	int data;
	Treenode* tree = NULL;

	while (scanf("%d", &data) != EOF) // Linux :: Ctrl + D
	{
		tree = insert_node(tree, data); // 이런 초기화 코드를 통해, 노드 삽입 함수가 ① node = NULL 의 경우에서 기능을 한다.
	}

	postorder(tree);
	return 0;
}