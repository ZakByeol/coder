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
