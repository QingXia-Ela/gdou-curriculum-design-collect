// linklist.c
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

// 头插法建立单链表
void CreateListF(LinkNode** L, ElemType a[], int n) {
    LinkNode* s;
    *L = (LinkNode*)malloc(sizeof(LinkNode));  // 创建头结点
    (*L)->next = NULL;
    for (int i = 0; i < n; i++) {
        s = (LinkNode*)malloc(sizeof(LinkNode)); // 创建新结点s
        s->data = a[i];
        s->next = (*L)->next;
        (*L)->next = s;
    }
}

// 尾插法建立单链表
void CreateListR(LinkNode** L, ElemType a[], int n) {
    LinkNode* s, * r;
    *L = (LinkNode*)malloc(sizeof(LinkNode));   // 创建头结点
    (*L)->next = NULL;
    r = *L;                                     // r始终指向尾结点,开始时指向头结点
    for (int i = 0; i < n; i++) {
        s = (LinkNode*)malloc(sizeof(LinkNode)); // 创建新结点s
        s->data = a[i];
        r->next = s;                             // 将结点s插入r结点之后
        r = s;
    }
    r->next = NULL;                             // 尾结点next域置为NULL
}

// 初始化线性表
void InitList(LinkNode** L) {
    *L = (LinkNode*)malloc(sizeof(LinkNode));   // 创建头结点
    (*L)->next = NULL;                          // 单链表置为空表
}

// 销毁线性表
void DestroyList(LinkNode** L) {
    LinkNode* pre, * p;
    p = *L;
    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    *L = NULL;
}

// 判线性表是否为空表
int ListEmpty(LinkNode* L) {
    return L->next == NULL;
}

// 求线性表的长度
int ListLength(LinkNode* L) {
    int i = 0;
    LinkNode* p = L->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

// 输出线性表
void DispList(LinkNode* L) {
    LinkNode* p = L->next;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 求线性表中第i个元素值
int GetElem(LinkNode* L, int i, ElemType* e) {
    int j = 0;
    LinkNode* p = L;
    while (j < i && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) return 0;
    *e = p->data;
    return 1;
}

// 查找第一个值域为e的元素序号
int LocateElem(LinkNode* L, ElemType e) {
    int i = 1;
    LinkNode* p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL) return 0;
    return i;
}

// 插入第i个元素
int ListInsert(LinkNode** L, int i, ElemType e) {
    int j = 0;
    LinkNode* p = *L, * s;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL || (i != 1 && p->next == NULL)) return 0;
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 删除第i个元素
int ListDelete(LinkNode** L, int i, ElemType* e) {
    int j = 0;
    LinkNode* p = *L, * q;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL || p->next == NULL) return 0;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}