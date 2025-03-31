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

void BinInsertSort(RecType R[], int n) {
    int i, j, low, high, mid;
    RecType tmp;
    for (i = 1; i < n; i++) {
        if (R[i].key < R[i - 1].key) { // 反序时
            printf("  i=%d，插入%d，插入结果: ", i, R[i].key);
            tmp = R[i]; // 将R[i]保存到tmp中
            low = 0; high = i - 1;
            while (low <= high) { // 在R[low..high]中查找插入的位置
                mid = (low + high) / 2; // 取中间位置
                if (tmp.key < R[mid].key)
                    high = mid - 1; // 插入点在左半区
                else
                    low = mid + 1; // 插入点在右半区
            }
            for (j = i - 1; j >= high + 1; j--) // 集中进行元素后移
                R[j + 1] = R[j];
            R[high + 1] = tmp; // 插入tmp
        }
        DispList(R, n);
    }
}