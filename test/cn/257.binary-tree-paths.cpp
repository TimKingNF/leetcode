//
// Created by timking.nf@foxmail.com on 2020/9/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "257.binary-tree-paths.h"

namespace LeetCode257 {

typedef string ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode257Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode257Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode257::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode *root = buildTreeBySerialize<TreeNode>(argument);
  ResultType asserted = solution->binaryTreePaths(root);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType("1,2,3,null,5", {"1->2->5", "1->3"}),
  ParamType("", {}),
  ParamType("1", {"1"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode257ParamTest, LeetCode257Test, values);

}