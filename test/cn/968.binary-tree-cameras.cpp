//
// Created by timking.nf@foxmail.com on 2020/9/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "968.binary-tree-cameras.h"

namespace LeetCode968 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode968Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode968Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode968::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->minCameraCover(root), ret);
}

auto values = ::testing::Values(
  ParamType("0,0,null,0,0", 1),
  ParamType("0,0,null,0,null,0,null,null,0", 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode968ParamTest, LeetCode968Test, values);

}