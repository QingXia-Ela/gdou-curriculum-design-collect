#include <bits/stdc++.h>
using namespace std;

string str;

template <class T>
struct Node
{
  T data;
  Node *lchild, *rchild;
};

void create(Node<char> *&T)
{
  if (!str.length())
    return;

  auto ch = str[0];
  str = str.substr(1, str.length() - 1);

  if (ch != '#')
  {
    T = new Node<char>();
    T->data = ch;
    create(T->lchild);
    create(T->rchild);
  }
  else
    T = nullptr;
}

template <class T>
class BiTree
{
public:
  Node<T> *root;
  BiTree(string input_str)
  {
    str = input_str;
    Node<T> *n = NULL;

    create(n);
    root = n;
  }; // 构造函数，建立一棵二叉树
  void preOrder()
  {
    _preOrder(root);
  }; // 前
  void inOrder()
  {
    _inOrder(root);
  }; // 中
  void postOrder()
  {
    _postOrder(root);
  };
  void inOrderWithoutRecursion()
  {
    _inOrderWithoutRecursion(root);
  }; // 非递归
  void layerOrder()
  {
    _layerOrder(root);
  };
  void swap()
  {
    _swap(root);
  };
  void getTreeNodeNum()
  {
    int num = 0;
    _getTreeNodeNum(root, &num);
    cout << "二叉树的结点个数为:" << num << endl;
  };
  void getTreeHeight()
  {
    cout << "二叉树的高度为:" << _getTreeHeight(root) << endl;
  };
  void getLeafCount()
  {
    int num = 0;
    _getLeafCount(root, &num);
    cout << "二叉树的叶子个数为:" << num << endl;
  };

private:
  // 前
  void _preOrder(Node<T> *n)
  {
    if (n)
    {
      cout << n->data;
      _preOrder(n->lchild);
      _preOrder(n->rchild);
    }
  };
  // 中
  void _inOrder(Node<T> *n)
  {
    if (n)
    {
      _inOrder(n->lchild);
      cout << n->data;
      _inOrder(n->rchild);
    }
  };
  void _postOrder(Node<T> *n)
  {
    if (n)
    {
      _postOrder(n->lchild);
      _postOrder(n->rchild);
      cout << n->data;
    } // 后
  };
  void _preOrderWithoutrecursion(Node<T> *n)
  {
    stack<Node<T> *> s;
    Node<T> *p = n;
    s.push(p);

    while (p)
    {
      p = s.top();
      s.pop();
      // 根节点
      cout << p->data;

      // 右
      if (p->rchild)
      {
        p = p->rchild;
        s.push(p);
      }

      // 左，先出栈
      if (p->lchild)
      {
        p = p->lchild;
        s.push(p);
      }
    }
  }
  void _inOrderWithoutRecursion(Node<T> *n)
  {
    stack<Node<T> *> s;
    Node<T> *p = n;

    while (p || !s.empty())
    {
      // 遍历到左节点最深处
      while (p)
      {
        s.push(p);
        p = p->lchild;
      }

      // 弹出，打印根节点值
      p = s.top();
      cout << p->data;
      s.pop();
      // 指向右节点，假如右节点为空则回到上面继续弹出
      p = p->rchild;
    }
  }; // 非递归
  void _postOrderWithoutrecursion(Node<T> *n)
  {
    stack<Node<T> *> s;
    Node<T> *p = n;

    while (p || !s.empty())
    {
      while (p)
      {
        s.push(p);
        // 左节点全部入栈
        if (p->lchild)
        {
          p = p->lchild;
        }
        else
        {
          p = p->rchild;
        }
      }

      // 没有左也没有右，弹出
      p = s.top();
      s.pop();
      cout << p->data;

      // 当前节点的上一个节点
      auto cur_p = s.top();

      // 栈不为空且上一个节点左节点为当前节点，说明当前左分支已经走完，将遍历转移至右节点并重复循环过程
      if (!s.empty() && cur_p->lchild == p)
      {
        p = cur_p->rchild;
      }
    }
  }
  void _layerOrder(Node<T> *n)
  {
    queue<Node<T> *> q;
    if (n)
    {
      q.push(n);
    }
    while (!q.empty())
    {
      Node<T> *p = q.front();
      q.pop();
      cout << p->data;
      if (p->lchild)
      {
        q.push(p->lchild);
      }
      if (p->rchild)
      {
        q.push(p->rchild);
      }
    }
  }; // 层次
  int _getTreeHeight(Node<T> *n)
  {
    if (n)
    {
      int leftHeight = _getTreeHeight(n->lchild);
      int rightHeight = _getTreeHeight(n->rchild);
      return max(leftHeight, rightHeight) + 1;
    }
    return 0;
  }; // 求二叉树的高度
  void _getTreeNodeNum(Node<T> *n, int *num)
  {
    if (n)
    {
      *num = *num + 1;
      _getTreeNodeNum(n->lchild, num);
      _getTreeNodeNum(n->rchild, num);
    }
  }; // 求二叉树的结点个数
  void _getLeafCount(Node<T> *n, int *count)
  {
    if (n)
    {
      if (!n->lchild && !n->rchild)
      {
        *count = *count + 1;
      }
      _getLeafCount(n->lchild, count);
      _getLeafCount(n->rchild, count);
    }
  }; // 求二叉树叶子个数
  void _swap(Node<T> *n)
  {
    if (n)
    {
      auto temp = n->lchild;
      n->lchild = n->rchild;
      n->rchild = temp;
      _swap(n->lchild);
      _swap(n->rchild);
    }
  }; // 交换节点
};

int main()
{
  string input;
  cout << "请输入要建立的二叉树字符序列：";
  // input ABC##DE#G##F##
  cin >> input;
  BiTree<char> *tree = new BiTree<char>(input);
  cout << endl;
  int choose = 0;
  do
  {
    cout << "请选择要进行的操作：" << endl;
    cout << "1:前序遍历" << endl;
    cout << "2:中序遍历" << endl;
    cout << "3:后序遍历" << endl;
    cout << "4:非递归遍历" << endl;
    cout << "5:层次遍历" << endl;
    cout << "6:计算叶子个数" << endl;
    cout << "7:计算结点个数" << endl;
    cout << "8:计算二叉树高度" << endl;
    cout << "9:交换整棵树" << endl;
    cout << "0:退出" << endl;

    cin >> choose;

    switch (choose)
    {
    case 1:
      tree->preOrder();
      cout << endl;
      break;
    case 2:
      tree->inOrder();
      cout << endl;
      break;
    case 3:
      tree->postOrder();
      cout << endl;
      break;
    case 4:
      tree->inOrderWithoutRecursion();
      cout << endl;
      break;
    case 5:
      tree->layerOrder();
      cout << endl;
      break;
    case 6:
      tree->getLeafCount();
      cout << endl;
      break;
    case 7:
      tree->getTreeNodeNum();
      cout << endl;
      break;
    case 8:
      tree->getTreeHeight();
      cout << endl;
      break;
    case 9:
      tree->swap();
      cout << endl;
      break;
    }
  } while (choose != 0);

  return 0;
}
