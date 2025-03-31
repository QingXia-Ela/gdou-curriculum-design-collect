#include "linklist.h"
#include <stdio.h>

int main() {
    LinkNode* h;
    ElemType e;
    printf("单链表的基本运算如下:\n");
    printf("  (1)初始化单链表h\n");
    InitList(&h);
    printf("  (2)依次采用尾插法插入a,b,c,d,e元素\n");
    ElemType elements[] = { 'a', 'b', 'c', 'd', 'e' };
    CreateListR(&h, elements, sizeof(elements) / sizeof(elements[0]));
    printf("  (3)输出单链表h:\n");
    DispList(h);
    printf("  (4)单链表h长度:%d\n", ListLength(h));
    printf("  (5)单链表h为%s\n", (ListEmpty(h) ? "空" : "非空"));
    if (GetElem(h, 3, &e)) {
        printf("  (6)单链表h的第3个元素:%c\n", e);
    }
    printf("  (7)元素a的位置:%d\n", LocateElem(h, 'a'));
    printf("  (8)在第4个元素位置上插入f元素\n");
    ListInsert(&h, 4, 'f');
    printf("  (9)输出单链表h:\n");
    DispList(h);
    printf("  (10)删除h的第3个元素\n");
    if (ListDelete(&h, 3, &e)) { 
        printf("  (11)输出单链表h:\n");
        DispList(h);
    }
    printf("  (12)释放单链表h\n");
    DestroyList(&h);
    return 0;
}