//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_26.shu-de-zi-jie-gou-lcof.h"

namespace LeetCode_26 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_26Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_26Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_26::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string firstArgs, secondArgs;
  tie(firstArgs, secondArgs) = arguments;
  TreeNode* first = buildTreeBySerialize<TreeNode>(firstArgs);
  TreeNode* second = buildTreeBySerialize<TreeNode>(secondArgs);

  ASSERT_EQ(solution->isSubStructure(first, second), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("1,2,3", "3,1"), false),
  ParamType(ArgumentType("3,4,5,1,2", "4,1"), true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_26ParamTest, LeetCode_26Test, values);

}
