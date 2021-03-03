//
// Created by timking.nf@foxmail.com on 2021/2/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_04_04.check-balance-lcci.h"

namespace LeetCode_04_04 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_04_04Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_04_04Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_04_04::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);

  ASSERT_EQ(solution->isBalanced(root), ret);
}

auto values = ::testing::Values(
  ParamType("3,9,20,null,null,15,7", true),
  ParamType("1,2,2,3,3,null,null,4,4", false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_04_04ParamTest, LeetCode_04_04Test, values);

}