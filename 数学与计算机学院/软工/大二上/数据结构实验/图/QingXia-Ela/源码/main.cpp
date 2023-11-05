#include <bits/stdc++.h>
using namespace std;

/**
 * 构造无向图邻接矩阵
 *
 * @param edges a vector of pairs representing the edges in the graph
 * @param size the size of the matrix
 *
 * @return a 2D vector representing the matrix graph
 *
 * @throws None
 */
vector<vector<int>> CreateMatGraph(vector<pair<int, int>> edges, int size)
{
  vector<vector<int>> matrix(size, vector<int>(size, 0));

  for (auto p : edges)
    matrix[p.first][p.second] = 1;

  // print matrix
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return matrix;
}

struct ArcNode
{
  int adjvex;
  ArcNode *next_arc = nullptr;
};

/**
 * 通过邻接表构造有向图
 *
 * @param edges a vector of pairs representing the edges of the graph
 * @param edge_count the total number of edges in the graph
 *
 * @return a vector of ArcNode pointers representing the adjacency list graph
 *
 * @throws None
 */
vector<ArcNode> CreateAdjGraph()
{
  int edge_count;
  cout << "请输入图的节点个数:";
  cin >> edge_count;
  vector<ArcNode> res(edge_count);

  while (true)
  {
    string head;
    cout << "请输入需要设置的节点:";
    cin >> head;
    cout << endl;

    if (head != ".exit")
    {
      int val = stoi(head);
      ArcNode head_node;
      head_node.adjvex = val;

      ArcNode *cur = &head_node;

      while (true)
      {
        string next_head;
        cout << "请输入该节点的邻接节点:";
        cin >> next_head;
        if (next_head != ".exit")
        {
          int valNext = stoi(next_head);
          ArcNode *next = new ArcNode();
          next->adjvex = valNext;
          cur->next_arc = next;
          cur = cur->next_arc;
        }
        else
          break;
      }
      res[val] = head_node;
      cout << endl;
    }
    else
      break;
  }

  return res;
}

void PrintAdjGraph(vector<ArcNode> &graph)
{
  cout << "图的邻接表如下:" << endl;
  for (int i = 0; i < graph.size(); i++)
  {
    cout << i << ": ";
    ArcNode *cur = &graph[i];
    while (cur != nullptr)
    {
      cout << cur->adjvex << "->";
      cur = cur->next_arc;
    }
    cout << endl;
  }
}

/**
 * 无向图（邻接表实现）
 */
vector<ArcNode *> UndirectGraph = {
    new ArcNode{0, new ArcNode{1, new ArcNode{3, new ArcNode{4, nullptr}}}},
    new ArcNode{1, new ArcNode{0, new ArcNode{2, new ArcNode{3, nullptr}}}},
    new ArcNode{2, new ArcNode{1, new ArcNode{3, new ArcNode{4, nullptr}}}},
    new ArcNode{3, new ArcNode{0, new ArcNode{1, new ArcNode{2, new ArcNode{4, nullptr}}}}},
    new ArcNode{4, new ArcNode{0, new ArcNode{2, new ArcNode{3, nullptr}}}},
};

/**
 * 非递归深度优先搜索
 *
 * @param graph 邻接表
 * @param v 起始节点
 *
 * @throws None
 */
void dfsNonRecursive(vector<ArcNode *> &graph, int v)
{
  vector<int> visited(graph.size(), 0);
  stack<int> s;
  s.push(v);
  visited[v] = 1;

  while (!s.empty())
  {
    int t = s.top();
    s.pop();
    cout << t << " ";
    ArcNode *cur = graph[t];
    while (cur != nullptr)
    {
      if (!visited[cur->adjvex])
      {
        s.push(cur->adjvex);
        visited[cur->adjvex] = 1;
      }
      cur = cur->next_arc;
    }
  }
}

void bfs(vector<ArcNode *> &graph)
{
  queue<int> q;
  vector<int> visited(graph.size(), 0);
  q.push(0);
  visited[0] = 1;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    cout << v << " ";
    ArcNode *cur = graph[v];
    while (cur != nullptr)
    {
      if (!visited[cur->adjvex])
      {
        q.push(cur->adjvex);
        visited[cur->adjvex] = 1;
      }
      cur = cur->next_arc;
    }
  }
}

int main()
{
  vector<ArcNode> Graph;
  while (true)
  {
    string choose;
    int final_choose = 7;
    cout << endl;
    cout << "1. 用邻接矩阵构造无向图" << endl
         << "2. 用邻接表构造有向图" << endl
         << "3. 输出有向图邻接表" << endl
         << "4. 非递归深度优先搜索遍历无向图" << endl
         << "5. 广度优先搜索遍历无向图" << endl
         << "6. 退出" << endl;

    cout << "请选择:";
    cin >> choose;
    try
    {
      final_choose = stoi(choose);
    }
    catch (const std::exception &e)
    {
    }

    switch (final_choose)
    {
    case 1:
      CreateMatGraph(
          {
              {0, 1},
              {0, 3},
              {0, 4},
              {1, 0},
              {1, 2},
              {1, 3},
              {2, 1},
              {2, 3},
              {2, 4},
              {3, 0},
              {3, 1},
              {3, 2},
              {3, 4},
              {4, 0},
              {4, 2},
              {4, 3},
          },
          5);
      cout << "构造完成" << endl;
      break;
    case 2:
    {
      vector<ArcNode> res = CreateAdjGraph();
      Graph = res;
      break;
    }
    case 3:
      if (&Graph == nullptr)
        cout << "请先构造图" << endl;
      else
        PrintAdjGraph(Graph);
      break;
    case 4:
      dfsNonRecursive(UndirectGraph, 0);
      break;
    case 5:
      bfs(UndirectGraph);
      break;
    case 6:
      return 0;
    default:
      cout << "输入错误" << endl;
    }
  }

  return 0;
}
