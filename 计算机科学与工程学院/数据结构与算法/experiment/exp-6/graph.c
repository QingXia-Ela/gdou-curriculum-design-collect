#include "graph.h"

void CreateMat(MatGraph* g, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    g->n = n; g->e = e;
    for (i = 0; i < g->n; i++)
        for (j = 0; j < g->n; j++)
            g->edges[i][j] = A[i][j];
}

void DispMat(MatGraph g) {
    int i, j;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] != INF)
                printf("%4d", g.edges[i][j]);
            else
                printf("%4s", "∞");
        printf("\n");
    }
}

void CreateAdj(AdjGraph** G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode* p, * tail = NULL;
    *G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) {
        (*G)->adjlist[i].info = '\0'; // 初始化顶点信息
        (*G)->adjlist[i].count = 0;   // 初始化入度
        (*G)->adjlist[i].firstarc = NULL; // 初始化邻接链表头指针
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = NULL; // 新建的节点指向NULL
                if ((*G)->adjlist[i].firstarc == NULL) {
                    (*G)->adjlist[i].firstarc = p; // 如果链表为空，新节点即为头节点
                }
                else {
                    // 找到链表的尾部并添加新节点
                    tail = (*G)->adjlist[i].firstarc;
                    while (tail->nextarc != NULL) {
                        tail = tail->nextarc;
                    }
                    tail->nextarc = p;
                }
            }
        }
    }
    (*G)->n = n; (*G)->e = e;
}

void DispAdj(AdjGraph* G) {
    ArcNode* p;
    for (int i = 0; i < G->n; i++) {
        printf("%d: ", i);
        int isFirst = 1; // 用于标记是否是第一个邻接点
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            if (!isFirst) {
                printf("→"); // 如果不是第一个邻接点，打印箭头
            }
            printf("%d[%d]", p->adjvex, p->weight);
            isFirst = 0; // 更新标记，表示已经打印了一个邻接点
            p = p->nextarc;
        }
        if (!isFirst) {
            printf("^\n"); // 如果有邻接点，打印结束符号
        }
        else {
            printf("^\n"); // 如果没有邻接点，也打印结束符号
        }
    }
}

void DestroyAdj(AdjGraph** G) {
    ArcNode* pre, * p;
    for (int i = 0; i < (*G)->n; i++) {
        pre = (*G)->adjlist[i].firstarc;
        if (pre != NULL) {
            p = pre->nextarc;
            while (p != NULL) {
                free(pre);
                pre = p; p = p->nextarc;
            }
            free(pre);
        }
    }
    free(*G);
    *G = NULL;
}