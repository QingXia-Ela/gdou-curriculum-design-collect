#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>
#define MAXL 100

typedef int KeyType; // 定义关键字类型为int

typedef struct {
    KeyType key; // 关键字项
    char data;   // 其他数据项，类型为char
} RecType;       // 查找元素的类型

void CreateList(RecType R[], KeyType keys[], int n);
void DispList(RecType R[], int n);
void InsertSort(RecType R[], int n);

#endif
