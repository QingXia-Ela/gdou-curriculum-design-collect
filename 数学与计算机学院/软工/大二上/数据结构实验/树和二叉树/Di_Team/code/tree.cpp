// tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <utility>
// #include <bits/stdc++.h>

using namespace std;

class treeNode
{
public:
    treeNode *left = nullptr;
    treeNode *right = nullptr;
    string strvalue = "";
};

class oprTree
{
public:
    treeNode *Root = new treeNode;
    vector<treeNode *> stack;
    oprTree(string s)
    {
        bool state = true;
        for (auto i : s)
        {
            treeNode *a = new treeNode;
            if (i != '#')
            {
                a->strvalue = i;
                if (stack.size() != 0)
                {
                    if (state)
                    {
                        Root->left = a;
                        Root = Root->left;
                    }
                    else
                    {
                        Root->right = a;
                        state = !state;
                        Root = Root->right;
                    }
                }
                else
                {
                    Root = a;
                }
                stack.push_back(a);
            }
            else
            {
                state = !state;
                if (state == true)
                {
                    stack.pop_back();
                    if (stack.back()->right != nullptr && stack.size() != 1)
                        stack.pop_back();
                    Root = stack.back();
                    state = !state;
                }
            }
        }
        Root = stack[0];
    };

    void recuForMid()
    {
        recu(Root);
    };

    static void recu(treeNode *Root)
    {
        if (Root == nullptr)
        {
            return;
        }
        recu(Root->left);
        cout << Root->strvalue;
        recu(Root->right);
    };

    void iterForMid(treeNode *Root)
    {
        stack.clear();
        while (Root != nullptr || !stack.empty())
        {
            while (Root != nullptr)
            {
                stack.push_back(Root);
                Root = Root->left;
            }
            Root = stack.back();
            stack.pop_back();
            cout << Root->strvalue;
            Root = Root->right;
        }
    };

    void checkForTier(treeNode *Root)
    {
        stack.clear();
        stack.push_back(Root);
        while (!stack.empty())
        {
            int queueSize = stack.size();
            for (int i = 0; i < queueSize; i++)
            {
                auto node = stack[0];
                cout << stack[0]->strvalue << "\0";
                stack.erase(stack.begin());
                if (node->left)
                    stack.push_back(node->left);
                if (node->right)
                    stack.push_back(node->right);
            }
            cout << endl;
        }
    };

    void checkHeight()
    {
        int l = 0;
        l = check(Root);
        cout << l << endl;
    };

    static int check(treeNode *Root)
    {
        if (Root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(check(Root->left), check(Root->right)) + 1;
        };
    }

    int checkNumOfPoint(treeNode *Root)
    {
        if (Root == nullptr)
        {
            return 0;
        }
        else
        {
            return checkNumOfPoint(Root->left) + checkNumOfPoint(Root->right) + 1;
        }
    };

    int checkNumOfLeaf(treeNode *Root)
    {
        if (Root == nullptr)
        {
            return 0;
        }
        else if (Root->left == nullptr && Root->right == nullptr)
        {
            return 1;
        }
        else
        {
            return (checkNumOfLeaf(Root->left) + checkNumOfLeaf(Root->right));
        }
    };

    void swapLandR(treeNode *Root)
    {
        if (Root == nullptr)
        {
            return;
        }
        else
        {
            swap(Root->left, Root->right);
            swapLandR(Root->left);
            swapLandR(Root->right);
        }
    };
};

int main()
{
    string init;
    cout << "先序输入二叉树（#代表空节点）\n";
    cin >> init;
    if (init[0] == '#')
    {
        cout << "别一开始就空吧\n";
        return 0;
    }
    oprTree tree(init);

    int opt = 0;
    while (true)
    {
        cout << "1.中序遍历二叉树\n";
        cout << "2.中序遍历二叉树（迭代实现）\n";
        cout << "3.层次遍历二叉树\n";
        cout << "4.求二叉树的高度\n";
        cout << "5.求二叉树的结点数\n";
        cout << "6.求二叉树的叶子数\n";
        cout << "7.交换二叉树的左右子树\n";
        cout << "8.退出程序\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "1.中序遍历二叉树结果是：\n";
            tree.recuForMid();
            break;
        case 2:
            cout << "2.中序遍历二叉树（迭代实现）结果是\n";
            tree.iterForMid(tree.Root);
            break;
        case 3:
            cout << "3.层次遍历二叉树结果是：\n";
            tree.checkForTier(tree.Root);
            break;
        case 4:
            cout << "4.二叉树的高度是：\n";
            tree.checkHeight();
            break;
        case 5:
            cout << "5.二叉树的结点数是：\n";
            cout << tree.checkNumOfPoint(tree.Root) << endl;
            break;
        case 6:
            cout << "6.二叉树的叶子数是：\n";
            cout << tree.checkNumOfLeaf(tree.Root) << endl;
            break;
        case 7:
            tree.swapLandR(tree.Root);
            cout << "已交换" << endl;
            break;
        case 8:
            return 0;

        default:
            cout << "输入不符合要求\n";
            break;
        }
        cout << "\n";
        system("pause");
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单