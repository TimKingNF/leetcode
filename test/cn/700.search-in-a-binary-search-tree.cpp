//
// Created by timking.nf@foxmail.com on 2020/8/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "700.search-in-a-binary-search-tree.h"

namespace LeetCode700 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

TreeNode* findNode(TreeNode* root, int val) {
  if (!root) return nullptr;
  if (root->val == val) return root;
  if (val < root->val) return findNode(root->left, val);
  else return findNode(root->right, val);
}

class LeetCode700Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode700Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode700::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int val;
  tie(args, val) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(args);
  TreeNode* resultNode = findNode(root, ret);

  ASSERT_EQ(solution->searchBST(root, val), resultNode);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("4,2,7,1,3", 2), 2),
  ParamType(ArgumentType("4,2,7,1,3", 5), 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode700ParamTest, LeetCode700Test, values);

}