//
// Created by timking.nf@foxmail.com on 2020/10/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "129.sum-root-to-leaf-numbers.h"

namespace LeetCode129 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode129Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode129Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode129::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode *root = buildTreeBySerialize<TreeNode>(argument);

  ASSERT_EQ(solution->sumNumbers(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,2,3", 25),
  ParamType("4,9,0,5,1", 1026),
  ParamType("0,1", 1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode129ParamTest, LeetCode129Test, values);

}
