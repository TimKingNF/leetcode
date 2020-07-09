//
// Created by timking.nf@foxmail.com on 2020/5/11.
//

#ifndef EDITORCN_HEAD_H
#define EDITORCN_HEAD_H

#include <vector>
#include <list>
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

/**
* 根据前序和中序的结果构造出一个二叉树
* @tparam T
* @tparam value_type
* @param preorder
* @param inorder
* @return
*/
template<typename T, typename value_type>
T* build_tree(vector<value_type>& preorder, vector<value_type>& inorder) {
  if (!preorder.size()) {
    return nullptr;
  }
  T* root = new T(preorder[0]);
  stack<T*> stk;
  stk.push(root);
  int inorderIndex = 0;
  for (int i = 1; i < preorder.size(); ++i) {
    int preorderVal = preorder[i];
    T* node = stk.top();
    if (node->val != inorder[inorderIndex]) {
      node->left = new T(preorderVal);
      stk.push(node->left);
    }
    else {
      while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
        node = stk.top();
        stk.pop();
        ++inorderIndex;
      }
      node->right = new T(preorderVal);
      stk.push(node->right);
    }
  }
  return root;
}

template<typename T, typename convert>
T* buildTreeBySerialize(string data) {
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

#endif  // EDITORCN_HEAD_H
