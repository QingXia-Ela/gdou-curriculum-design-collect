#define  _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"

void CreateList(RecType R[], KeyType keys[], int n) {
    for (int i = 0; i < n; i++) {
        R[i].key = keys[i];
        R[i].data = ' '; // 初始化其他数据项
    }
}

void DispList(RecType R[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", R[i].key);
    }
    printf("\n");
}

void InsertSort(RecType R[], int n) {
    int i, j;
    RecType tmp;
    for (i = 1; i < n; i++) {
        printf("  i=%d，插入%d，插入结果: ", i, R[i].key);
        if (R[i].key < R[i - 1].key) { // 反序时
            tmp = R[i];
            j = i - 1;
            do { // 找R[i]的插入位置
                R[j + 1] = R[j]; // 将关键字大于R[i].key的记录后移
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            R[j + 1] = tmp; // 在j+1处插入R[i]
        }
        DispList(R, n);
    }
}