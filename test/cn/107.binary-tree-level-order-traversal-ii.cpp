//
// Created by timking.nf@foxmail.com on 2020/9/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "107.binary-tree-level-order-traversal-ii.h"

namespace LeetCode107 {

typedef string ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode107Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode107Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode107::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->levelOrderBottom(root), ret);
}

auto values = ::testing::Values(
  ParamType("3,9,20,null,null,15,7", {{15,7}, {9,20}, {3}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode107ParamTest, LeetCode107Test, values);

}