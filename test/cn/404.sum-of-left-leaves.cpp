//
// Created by timking.nf@foxmail.com on 2020/9/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "404.sum-of-left-leaves.h"

namespace LeetCode404 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode404Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode404Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode404::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->sumOfLeftLeaves(root), ret);
}

auto values = ::testing::Values(
  ParamType("3,9,20,null,null,15,7", 24)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode404ParamTest, LeetCode404Test, values);

}