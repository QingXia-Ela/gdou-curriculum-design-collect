// betree.h
#ifndef BETREE_H
#define BETREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* lchild, * rchild;
} BTNode;

void CreateBTree(BTNode** b, const char* str);
void DestroyBTree(BTNode* b);
void DispBTree(BTNode* b);
void PreOrder(BTNode* b);
void PreOrder1(BTNode* b);
void InOrder(BTNode* b);
void InOrder1(BTNode* b);
void PostOrder(BTNode* b);
void PostOrder1(BTNode* b);
void TravLevel(BTNode* b);

#endif // BETREE_H