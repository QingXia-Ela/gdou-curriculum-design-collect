#include <bits/stdc++.h>
using namespace std;

void simple_choice_sort(vector<int> &a)
{
  int len = a.size();
  for (int i = 0; i < len - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < len; j++)
    {
      if (a[j] < a[min])
      {
        min = j;
      }
    }
    swap(a[i], a[min]);
  }

  cout << "简单选择排序后的数组为:" << endl;
  for (int i = 0; i < len; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

void bubble_sort(vector<int> &a)
{
  int len = a.size();
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - 1 - i; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
      }
    }
  }

  cout << "冒泡排序后的数组为:" << endl;
  for (int i = 0; i < len; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

void insert_sort(vector<int> &a)
{
  vector<int> temp({a[0]});

  for (int i = 1; i < a.size(); i++)
  {
    int index = 0;
    for (int j = 0; j < temp.size(); j++, index++)
    {
      if (temp[j] > a[i])
      {
        break;
      }
    }

    if (index == temp.size())
    {
      temp.push_back(a[i]);
    }
    else
    {
      temp.insert(temp.begin() + index, a[i]);
    }
  }

  cout << "直接插入排序后的数组为:" << endl;
  int index = 0;
  for (auto i : temp)
  {
    cout << i << " ";
    a[index++] = i;
  }
  cout << endl;
}

void select_sort(vector<int> &a)
{
  int k;
  int n = a.size();
  for (int i = 1; i < n; i++)
  {
    k = i;
    for (int j = i + 1; j <= n; j++)
    {
      if (a[j] < a[k])
      {
        k = j;
      }
    }
    if (i != k)
    {
      int temp;
      temp = a[k];
      a[k] = a[i];
      a[i] = temp;
    }
  }

  cout << "选择排序后的数组为:" << endl;
  for (auto i : a)
  {
    cout << i << " ";
  }
  cout << endl;
}

/**
 * 插入排序
 *
 * 仅供shell排序使用
 */
void insert_sort(vector<int>::iterator begin, vector<int>::iterator end, int step)
{
  for (vector<int>::iterator i = begin + step; i < end; i += step)
  {
    int temp = *i;
    vector<int>::iterator j;
    for (j = i; j > begin; j -= step)
    {
      if (*j < *(j - step))
      {
        swap(*j, *(j - step));
      }
      else
      {
        break;
      }
    }
  }
}

void shell_sort(vector<int> &a)
{
  int gap = a.size() / 2;
  while (gap > 0)
  {
    for (int i = 0; i < gap; i++)
    {
      insert_sort(a.begin() + i, a.end(), gap);
    }
    gap /= 2;
  }

  cout << "希尔排序后的数组为:" << endl;
  for (auto i : a)
  {
    cout << i << " ";
  }
  cout << endl;
}

vector<int> quick_sort_recursion(vector<int> a)
{
  vector<int> res;
  if (a.size() <= 1)
  {
    return a;
  }

  int pivot = a[0];
  vector<int> left;
  vector<int> right;

  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] < pivot)
    {
      left.push_back(a[i]);
    }
    else
    {
      right.push_back(a[i]);
    }
  }

  left = quick_sort_recursion(left);
  right = quick_sort_recursion(right);

  left.push_back(pivot);

  for (auto i : left)
  {
    res.push_back(i);
  }

  for (auto i : right)
  {
    res.push_back(i);
  }

  return res;
}

void quick_sort(vector<int> &a)
{
  vector<int> res = quick_sort_recursion(a);
  cout << "快速排序后的数组为:" << endl;
  for (auto i : res)
  {
    cout << i << " ";
  }
  cout << endl;
}

void heap_adjust(vector<int> &a, int n, int i)
{
  int max = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && a[left] > a[max])
  {
    max = left;
  }
  if (right < n && a[right] > a[max])
  {
    max = right;
  }
  if (max != i)
  {
    swap(a[i], a[max]);
    heap_adjust(a, n, max);
  }
}

void heap_sort(vector<int> &a)
{
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heap_adjust(a, n, i);
  }
  for (int i = n - 1; i > 0; i--)
  {
    swap(a[0], a[i]);
    heap_adjust(a, i, 0);
  }

  cout << "堆排序后的数组为:" << endl;
  for (auto i : a)
  {
    cout << i << " ";
  }
  cout << endl;
}

void bin_insert_sort(vector<int> &a)
{
  int n = a.size();
  for (int i = 1; i < n; i++)
  {
    int temp = a[i];
    int left = 0;
    int right = i - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (a[mid] > temp)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    for (int j = i - 1; j >= left; j--)
    {
      a[j + 1] = a[j];
    }
    a[left] = temp;
  }

  cout << "折半插入排序后的数组为:" << endl;
  for (auto i : a)
  {
    cout << i << " ";
  }
  cout << endl;
}

int main()
{

  int choose;
  // 生成一个菜单，用于对上面所有算法进行调试
  while (true)
  {
    vector<int> a({0, 3, 32, 5, 1, 2, 4, 6, 7, 8, 9});
    cout << "请选择排序算法:" << endl
         << "0.简单选择排序" << endl
         << "1.直接插入排序" << endl
         << "2.冒泡排序" << endl
         << "3.希尔排序" << endl
         << "4.快速排序" << endl
         << "5.堆排序" << endl
         << "6.折半插入排序" << endl
         << "7.退出" << endl;
    cin >> choose;
    switch (choose)
    {
    case 0:
      simple_choice_sort(a);
      break;
    case 1:
      insert_sort(a);
      break;
    case 2:
      bubble_sort(a);
      break;
    case 3:
      shell_sort(a);
      break;
    case 4:
      quick_sort(a);
      break;
    case 5:
      heap_sort(a);
      break;
    case 6:
      bin_insert_sort(a);
      break;
    case 7:
      return 0;
    default:
      cout << "输入错误" << endl;
    }
  }

  return 0;
}