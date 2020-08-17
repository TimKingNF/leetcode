//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_28.dui-cheng-de-er-cha-shu-lcof.h"

namespace LeetCode_28 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_28Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_28Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_28::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
   ASSERT_EQ(solution->isSymmetric(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,2,2,3,4,4,3", true),
  ParamType("1,2,2,null,3,null,3", false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_28ParamTest, LeetCode_28Test, values);

}
