//
// Created by timking.nf@foxmail.com on 2020/7/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "116.populating-next-right-pointers-in-each-node.h"

namespace LeetCode116 {

typedef string ArgumentType;
typedef vector<pair<int, string>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

Node* findNode(Node* root, int v) {
  if (!root) return nullptr;
  if (root->val == v) return root;
  Node* left = findNode(root->left, v);
  Node* right = findNode(root->right, v);
  if (!left) return right;
  if (!right) return left;
  return nullptr;
}

class LeetCode116Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode116Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode116::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  Node* root = buildTreeBySerialize<Node, convert>(argument);
  solution->connect(root);

  // 验证
  for (auto v : ret) {
    Node* pre_node = findNode(root, v.first);
    Node* next_node = v.second == "null" ? nullptr : findNode(root, stoi(v.second));
    ASSERT_EQ(pre_node->next, next_node);
  }
}

auto values = ::testing::Values(
  ParamType("1,2,3", {{1, "null"},
                      {2, "3"},
                      {3, "null"}}),
  ParamType("1,2,3,4,5,6,7", {{1, "null"},
                              {2, "3"},
                              {3, "null"},
                              {4, "5"},
                              {5, "6"},
                              {6, "7"},
                              {7, "null"}}),
  ParamType("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15", {{1, "null"},
                                                    {2, "3"},
                                                    {3, "null"},
                                                    {4, "5"},
                                                    {5, "6"},
                                                    {6, "7"},
                                                    {7, "null"},
                                                    {8, "9"},
                                                    {9, "10"},
                                                    {10, "11"},
                                                    {11, "12"},
                                                    {12, "13"},
                                                    {13, "14"},
                                                    {14, "15"},
                                                    {15, "null"}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode116ParamTest, LeetCode116Test, values);

}