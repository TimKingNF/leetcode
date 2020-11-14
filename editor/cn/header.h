//
// Created by timking.nf@foxmail.com on 2020/5/11.
//

#ifndef EDITORCN_HEAD_H
#define EDITORCN_HEAD_H

#include <vector>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>  // std::multiplies
#include <numeric>  // std::accumulate
#include <bitset>

using namespace std;

/**
* 打印 vector
* @tparam T
* @param nums
*/
template<typename T>
void vector_print(vector<T>& nums) {
   ostream_iterator<T> out_it(cout, ", ");
   copy(nums.begin(), nums.end(), out_it);
   cout << endl;
}

/**
* 无序比较两个vector
* @tparam T
* @param first
* @param second
* @return
*/
template<typename T>
bool vector_unordered_cmp(vector<T>& first, vector<T>& second) {
  if (first.size() != second.size()) {
    return false;
  }
  for (T item : first) {
    if (::find(second.begin(), second.end(), item) == second.end()) {
      return false;
    }
  }
  return true;
}

/**
* 无序比较二维数组
* @param first
* @param second
* @return
*/
template <typename value>
bool double_vector_cmp(vector<vector<value>>& first,
                       vector<vector<value>>& second) {
  if (first.size() != second.size()) return false;
  vector<value> cur;
  for (int i = 0; i < first.size(); ++i) {
    cur = first[i];
    bool flag = false;
    for (int j = 0; j < second.size(); ++j) {
      if (cur.size() != second[j].size()) flag = false;
      else if (vector_unordered_cmp(cur, second[j])) {
        flag = true;
        break;
      }
    }
    if (!flag) return false;
  }
  return true;
}

/**
* 构造一个链表
* @tparam T
* @tparam value
* @param input_list
* @return
*/
template<typename T, typename value_type>
T* construct_link_list(vector<value_type>& input_list) {
  if (input_list.empty()) return nullptr;

  T* head = new T(input_list[0]);
  T* tmp = head;
  T* new_node;
  for (int i = 1; i < input_list.size(); ++i) {
    new_node = new T(input_list[i]);
    tmp->next = new_node;
    tmp = new_node;
  }
  return head;
}

/**
* 两个链表比较，顺序值相同即可
* @tparam T
* @param first
* @param second
* @return
*/
template<typename T>
bool link_list_cmp(T* first, T* second) {
  while (first != nullptr && second != nullptr) {
    if (first->val != second->val) return false;
    first = first->next;
    second = second->next;
  }
  return first == nullptr && second == nullptr;  // 两个都为空指针时，说明比较完毕，两个链表值相同
}

/**
* 打印链表
* @tparam T
* @param root
*/
template<typename T>
void link_list_print(T* root) {
  while (root) {
    cout << root->val << "->";
    root = root->next;
  }
  cout << endl;
}

/**
* 前序遍历一个二叉树, 不使用递归
* @tparam T
* @tparam value_type
* @param tree
* @return
*/
template<typename T, typename value_type>
vector<value_type> preorder_range_binary_tree(T* tree) {
  stack<T*> stack_tree;
  vector<value_type> res;
  T* p = tree;
  while (p != nullptr || !stack_tree.empty()) {
    while (p != nullptr) {
      res.push_back(p->val);
      stack_tree.push(p);
      p = p->left;
    }
    if (!stack_tree.empty()) {
      p = stack_tree.top();
      stack_tree.pop();
      p = p->right;
    }
  }
  return res;
}

/**
* 中序遍历一个二叉树
* @tparam T
* @tparam value_type
* @param tree
* @return
*/
template<typename T, typename value_type>
vector<value_type> inorder_range_binary_tree(T* tree) {
  stack<T*> stack_tree;
  vector<value_type> res;
  T* p = tree;
  while (p != nullptr || !stack_tree.empty()) {
    while (p != nullptr) {
      stack_tree.push(p);
      p = p->left;
    }
    if (!stack_tree.empty()) {
      p = stack_tree.top();
      stack_tree.pop();
      res.push_back(p->val);  // 中序
      p = p->right;
    }
  }
  return res;
}

/**
* 后序遍历一个二叉树
* @tparam T
* @tparam value_type
* @param tree
* @return
*/
template<typename T, typename value_type>
vector<value_type> postorder_range_binary_tree(T* tree) {
  stack<T*> stack_tree;
  T* p = tree;
  T* r;  // 指向最近访问过的节点
  vector<value_type> res;
  while (p != nullptr || !stack_tree.empty()) {
    if (p != nullptr) {  // 先走到最左边的节点
      stack_tree.push(p);
      p = p->left;
    } else {
      p = stack_tree.top();
      if (p->right != nullptr && p->right != r)  // 右子数存在且未被访问
        p = p->right;
      else {
        stack_tree.pop();
        res.push_back(p->val);
        r = p;
        p = nullptr;
      }
    }
  }
  return res;
}

struct convert_stoi {
  int operator() (string v) {
    return stoi(v);
  }

  int operator() (char* v) {
    return stoi(v);
  }
};

/**
* 将字符串反序列化为二叉树
* @tparam T
* @tparam convert
* @param data
* @return
*/
template<typename T, typename convert>
T* buildTreeBySerialize(string data) {
  if (data.empty()) return nullptr;
  istringstream input(data);  // 没有 []
  string val;
  vector<T*> vec;
  convert func;
  while (getline(input, val, ',')) {
    if (val == "null")
      vec.push_back(nullptr);
    else
      vec.push_back(new T(func(val)));
  }
  // 构造成二叉树
  int j = 1;  // i每往后移动一位，j就移动两位
  for (int i = 0; j < vec.size(); ++i) {  // j先到达边界
    if (vec[i] == nullptr) continue;
    vec[i]->left = vec[j++];
    if (j < vec.size()) vec[i]->right = vec[j++];
  }
  return vec[0];
}

/**
* 将字符串反序列化为二叉树
* @tparam T
* @param data
* @return
*/
template<typename T>
T* buildTreeBySerialize(string data) {
  return buildTreeBySerialize<T, convert_stoi>(data);
}

/**
* 将二叉树序列化为字符串
* @tparam T
* @param root
* @return
*/
template<typename T>
string treeSerialize(T* root) {
  ostringstream out;  // 使用 ostream 代替 string
  deque<T*> q;
  q.push_back(root);
  T* tmp;
  int curNum = 1;  // 用该变量记录实际的元素
  while (!q.empty()) {
    tmp = q.front();
    q.pop_front();
    if (tmp) {
      out << tmp->val << ',';
      --curNum;
      q.push_back(tmp->left);
      if (tmp->left) ++curNum;
      q.push_back(tmp->right);
      if (tmp->right) ++curNum;
    } else if (curNum) out << "null,";
  }
  string ans = out.str();
  return ans.substr(0, ans.size()-1);
}

/**
* 将字符串反序列化为N叉树
* @tparam T
* @tparam convert
* @param data
* @return
*/
template<typename T, typename convert>
T* buildNTreeBySerialize(string data) {
  int n = data.size();
  if (n == 0 || data == "[]") return nullptr;
  const string up_bracket = "[";

  convert func;
  stack<pair<int, void*>> stk;
  for (int i = 1; i < n-1; ++i) {  // 排除掉头尾 []
    if (data[i] == ' ') continue;
    else if (data[i] == '[') {
      stk.push({0, (void*) up_bracket.c_str()});
    } else if (isdigit(data[i])) {
      ostringstream os;
      os.put(data[i]);
      int size = 1;
      // 取到所有的数字
      while (i + 1 < n && isdigit(data[i+1])) {
        os.put(data[i+1]);
        ++i;
        ++size;
      }
      char* num = new char[size+1];
      os.str().copy(num, size);
      num[size] = '\0';
      stk.push({0, (void*) num});  // char* 转为 void*, 记下类型为 0
    } else {  // "]"
      // 从栈顶取出数据, 构造 vector
      vector<T*> children;
      // 如果不是 T* ，则需要 char* 判断不为 "["
      while (stk.top().first != 0 || ((char*) stk.top().second) != up_bracket.c_str()) {
        if (stk.top().first == 1) {
          children.push_back((T*) stk.top().second);
        } else {
          children.push_back(new T(func((char*) stk.top().second)));
        }
        stk.pop();
      }
      stk.pop();  // pop 掉 "[", 接下来是父节点
      // 要保证和原数组完全一样的话
      children = vector<T*>(children.rbegin(), children.rend());
      T* parent = new T(func((char*) stk.top().second), children);
      stk.pop();  // pop 父节点字符串
      stk.push({1, (void*) parent});  // T* 转为 void*, 记下类型为 1
    }
  }
  if (stk.top().first == 0) {  // 只有一个元素的时候
    return new T(func((char*)stk.top().second));
  }
  return (T*) stk.top().second;  // 最后一个元素一定是 root
}

/**
* 将字符串反序列化为二叉树
* @tparam T
* @param data
* @return
*/
template<typename T>
T* buildNTreeBySerialize(string data) {
  return buildNTreeBySerialize<T, convert_stoi>(data);
}

#endif  // EDITORCN_HEAD_H
