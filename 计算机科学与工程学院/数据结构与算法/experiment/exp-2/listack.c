// listack.c
#include "listack.h"
#include <stdio.h>
#include <stdlib.h>

void InitStack(LinkStNode** s) {
    *s = (LinkStNode*)malloc(sizeof(LinkStNode));
    (*s)->next = NULL;
}

void DestroyStack(LinkStNode** s) {
    LinkStNode* p, * q;
    p = *s;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    *s = NULL;
}

int StackEmpty(LinkStNode* s) {
    return s->next == NULL;
}

void Push(LinkStNode* s, ElemType e) {
    LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

int Pop(LinkStNode* s, ElemType* e) {
    if (s->next == NULL) {
        return 0;  // 栈空，出栈失败
    }
    LinkStNode* p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
    return 1;  // 出栈成功
}