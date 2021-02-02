//
// Created by timking.nf@foxmail.com on 2020/7/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "430.flatten-a-multilevel-doubly-linked-list.h"

namespace LeetCode430 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

Node* constructMultiLinkedList(string data) {
  if (data.empty()) return nullptr;
  istringstream input(data);
  string val;
  vector<Node*> vec;
  convert func;
  Node* cur;
  while (getline(input, val, ',')) {
    if (val == "null") vec.push_back(nullptr);
    else {
      cur = new Node();
      cur->val = func(val);
      vec.push_back(cur);
    }
  }
  // 构造
  Node *pre, *dummy = new Node(), *pre_level_head = dummy;
  bool firstNull = true, firstItem = false;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i]) {
      // cout << vec[i]->val << endl;
      firstNull = true;
      if (!firstItem) {  // 表示当前还没遍历到当前level的第一个元素
        firstItem = true;
        pre_level_head->child = vec[i];
        pre = vec[i];
      } else {
        pre->next = vec[i];
        vec[i]->prev = pre;
        pre = vec[i];
      }
    } else {
      // cout << vec[i] << endl;
      if (firstNull) {
        firstNull = false;  // 表示当前的 nullptr 已经是下一级了
        pre_level_head = pre_level_head->child;  // 往下走下一级
        continue;
      }
      pre_level_head = pre_level_head->next;
      firstItem = false;  // 进入下一级，firstItem 置为 false
    }
  }
  return dummy->child;
}

void multiLinkedListPrint(Node* head) {
  while (head && (head->next || head->child)) {
    Node* cur = head;
    while (cur) {
      cout << cur->val << ",";
      cur = cur->next;
    }
    cout << endl;

    // 找到第一个有child的
    while (head && !head->child) {
      cout << "null,";
      head = head->next;
    }
    if (head) head = head->child;
  }
}

bool validDoubleLinkedList(Node* head) {
  if (!head) return false;
  if (head->prev) return false;
  Node *pre = new Node(), *origHead = head;
  pre->next = head;
  head->prev = pre;
  while (head) {
    if (head->prev != pre) return false;
    if (pre->next != head) return false;
    pre = head;
    head = head->next;
  }
  origHead->prev = nullptr;  // 恢复原状
  return true;
}

class LeetCode430Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode430Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode430::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  Node* head = constructMultiLinkedList(argument);
  // multiLinkedListPrint(head);
  // vector_print(ret);
  Node* resultHead = construct_link_list<Node>(ret);
  // cout << "--------" << endl;
  Node* assertedHead = solution->flatten(head);
  ASSERT_TRUE(validDoubleLinkedList(assertedHead));
  ASSERT_TRUE(link_list_cmp(assertedHead, resultHead));
}

auto values = ::testing::Values(
  ParamType("1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12", {1,2,3,7,8,11,12,9,10,4,5,6}),
  ParamType("1,2,3,4,5,6,null,null,null,7,8,null,null,11,12", {1,2,3,7,8,11,12,4,5,6})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode430ParamTest, LeetCode430Test, values);

}