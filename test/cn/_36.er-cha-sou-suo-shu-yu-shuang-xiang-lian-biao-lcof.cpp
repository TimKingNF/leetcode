//
// Created by timking.nf@foxmail.com on 2020/6/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_36.er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof.h"

namespace LeetCode_36 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

// 打印该循环链表
vector<int> printLinkList(Node* root) {
  if (!root) return {};
  vector<int> ans{root->val};
  Node* head = root;
  root = root->right;
  while (root != head) {
    ans.push_back(root->val);
    root = root->right;
  }
  return ans;
}

// 校验是否双向链表
bool checkDoublyList(Node* root) {
  if (!root) return false;
  Node *head = root, *leftHead = root, *rightHead = root;
  int leftCount = 0, rightCount = 0;
  while (leftHead && leftHead != head) {
    ++leftCount;
    leftHead = leftHead->left;
  }
  while (rightHead && rightHead != head) {
    ++rightCount;
    rightHead = rightHead->right;
  }
  return leftCount == rightCount;  // 向左遍历和向右遍历，长度相等
}

class LeetCode_36Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_36Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_36::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  Node* root = buildTreeBySerialize<Node>(argument);
  Node* orderLinkList = solution->treeToDoublyList(root);
  ASSERT_EQ(printLinkList(orderLinkList), ret);
  ASSERT_TRUE(checkDoublyList(orderLinkList));
}

auto values = ::testing::Values(
  ParamType("4,2,5,1,3", {1, 2, 3, 4, 5}),
  ParamType("2,1", {1, 2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_36ParamTest, LeetCode_36Test, values);

}