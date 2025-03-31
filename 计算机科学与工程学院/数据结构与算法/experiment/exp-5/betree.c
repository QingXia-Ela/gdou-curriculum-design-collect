#include "betree.h"
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

void CreateBTree(BTNode** b, const char* str) {
    BTNode* St[MaxSize], * p = NULL;
    int top = -1, k, j = 0;
    char ch;
    *b = NULL;
    ch = str[j];
    while (ch != '\0') {
        switch (ch) {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode*)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (*b == NULL) {
                *b = p;
            }
            else {
                switch (k) {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DestroyBTree(BTNode* b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

void DispBTree(BTNode* b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL) printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

void PreOrder(BTNode* b) {
    if (b != NULL) {
        printf("%c ", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void PreOrder1(BTNode* b) {
    BTNode* St[MaxSize], * p = b;
    int top = -1;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            printf("%c ", p->data);
            top++;
            St[top] = p;
            p = p->lchild;
        }
        if (top != -1) {
            p = St[top--];
            p = p->rchild;
        }
    }
    printf("\n");
}

void InOrder(BTNode* b) {
    if (b != NULL) {
        InOrder(b->lchild);
        printf("%c ", b->data);
        InOrder(b->rchild);
    }
}

void InOrder1(BTNode* b) {
    BTNode* St[MaxSize], * p = b;
    int top = -1;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            top++;
            St[top] = p;
            p = p->lchild;
        }
        if (top != -1) {
            p = St[top--];
            printf("%c ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

void PostOrder(BTNode* b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ", b->data);
    }
}

void PostOrder1(BTNode* b) {
    BTNode* St[MaxSize], * p = b;
    int top = -1;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            St[++top] = p;
            p = p->lchild;
        }
        if (top != -1) {
            p = St[top--];
            if (p->rchild == NULL || p->rchild == St[top + 1]) {
                printf("%c ", p->data);
                p = NULL;
            }
            else {
                p = p->rchild;
            }
        }
    }
    printf("\n");
}

void TravLevel(BTNode* b) {
    BTNode* Qu[MaxSize];
    int front = 0, rear = 0;
    if (b != NULL) {
        printf("%c ", b->data);
        rear++;
        Qu[rear] = b;
    }
    while (rear != front) {
        front = (front + 1) % MaxSize;
        BTNode* p = Qu[front];
        if (p->lchild != NULL) {
            printf("%c ", p->lchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = p->lchild;
        }
        if (p->rchild != NULL) {
            printf("%c ", p->rchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = p->rchild;
        }
    }
    printf("\n");
}