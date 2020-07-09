//
// Created by timking.nf@foxmail.com on 2020/5/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_07.zhong-jian-er-cha-shu-lcof.h"

namespace LeetCode_07 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef TreeNode* ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_07Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_07Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_07::Solution();
  ArgumentType arguments = GetParam();

  vector<int> preorder, inorder;
  tie(preorder, inorder) = arguments;

  ResultType tree = solution->buildTree(preorder, inorder);

  // 对树重新进行前序与中序遍历
  vector<int> preorder_ret = preorder_range_binary_tree<TreeNode, int>(tree);
  vector<int> inorder_ret = inorder_range_binary_tree<TreeNode, int>(tree);
  ASSERT_EQ(preorder_ret, preorder);
  ASSERT_EQ(inorder_ret, inorder);

  delete tree;
}

ArgumentType p1({3,9,20,15,7}, {9,3,15,20,7});

auto values = ::testing::Values(
  p1
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_07ParamTest, LeetCode_07Test, values);

}
