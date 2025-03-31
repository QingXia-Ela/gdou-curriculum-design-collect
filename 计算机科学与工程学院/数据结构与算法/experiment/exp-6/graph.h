#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define INF 32767
#define MAXV 100
typedef char InfoType;

// 顶点类型
typedef struct {
    int no;
    InfoType info;
} VertexType;

// 邻接矩阵类型
typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MatGraph;

// 边节点类型
typedef struct ANode {
    int adjvex;
    struct ANode* nextarc;
    int weight;
} ArcNode;

// 邻接表头节点类型
typedef struct VNode {
    InfoType info;
    int count;
    ArcNode* firstarc;
} VNode;

// 邻接表类型
typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;

// 函数声明
void CreateMat(MatGraph* g, int A[MAXV][MAXV], int n, int e);
void DispMat(MatGraph g);
void CreateAdj(AdjGraph** G, int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph* G);
void DestroyAdj(AdjGraph** G);

#endif