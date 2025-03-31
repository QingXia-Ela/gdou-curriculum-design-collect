#define  _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    CreateList(R, a, n);
    printf("排序前: ");
    DispList(R, n);
    BinInsertSort(R, n);
    printf("排序后: ");
    DispList(R, n);
    return 0;
}