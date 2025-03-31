// listack.h
#ifndef LISTACK_H
#define LISTACK_H

typedef char ElemType;

typedef struct linknode {
    ElemType data;
    struct linknode* next;
} LinkStNode;

void InitStack(LinkStNode** s);
void DestroyStack(LinkStNode** s);
int StackEmpty(LinkStNode* s);
void Push(LinkStNode* s, ElemType e);
int Pop(LinkStNode* s, ElemType* e);

#endif // LISTACK_H