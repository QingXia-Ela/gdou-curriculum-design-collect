// betree.h
#ifndef BETREE_H
#define BETREE_H

#define MaxSize 100  // 定义最大栈大小

typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node* lchild, * rchild;
} BTNode;

void CreateBTree(BTNode** b, const char* str);
void DestroyBTree(BTNode* b);
BTNode* FindNode(BTNode* b, ElemType x);
BTNode* LchildNode(BTNode* p);
BTNode* RchildNode(BTNode* p);
int BTHeight(BTNode* b);
void DispBTree(BTNode* b);

#endif // BETREE_H