#include "betree.h"

int main() {
    BTNode* b = NULL;
    CreateBTree(&b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b:"); DispBTree(b); printf("\n");

    printf("层次遍历序列: ");
    TravLevel(b);
    printf("\n");

    printf("先序遍历序列:\n");
    printf("    递归算法: ");
    PreOrder(b);
    printf("\n");
    printf("  非递归算法: ");
    PreOrder1(b);
    printf("\n");

    printf("中序遍历序列:\n");
    printf("    递归算法: ");
    InOrder(b);
    printf("\n");
    printf("  非递归算法: ");
    InOrder1(b);
    printf("\n");

    printf("后序遍历序列:\n");
    printf("    递归算法: ");
    PostOrder(b);
    printf("\n");
    printf("  非递归算法: ");
    PostOrder1(b);
    printf("\n");

    DestroyBTree(b);
    return 0;
}