// linklist.h
#ifndef LINKLIST_H
#define LINKLIST_H

typedef char ElemType;

// 单链表节点结构体定义
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LinkNode;

// 函数声明
void CreateListF(LinkNode** L, ElemType a[], int n);
void CreateListR(LinkNode** L, ElemType a[], int n);
void InitList(LinkNode** L);
void DestroyList(LinkNode** L);
int ListEmpty(LinkNode* L);
int ListLength(LinkNode* L);
void DispList(LinkNode* L);
int GetElem(LinkNode* L, int i, ElemType* e); // 修改这里，使用指针
int LocateElem(LinkNode* L, ElemType e);
int ListInsert(LinkNode** L, int i, ElemType e);
int ListDelete(LinkNode** L, int i, ElemType* e); // 修改这里，使用指针

#endif // LINKLIST_H