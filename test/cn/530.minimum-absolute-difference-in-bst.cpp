//
// Created by timking.nf@foxmail.com on 2020/10/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "530.minimum-absolute-difference-in-bst.h"

namespace LeetCode530 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode530Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode530Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode530::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode *root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->getMinimumDifference(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,null,3,2", 1),
  ParamType("1,null,5,3", 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode530ParamTest, LeetCode530Test, values);

}