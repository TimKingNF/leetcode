//
// Created by timking.nf@foxmail.com on 2021/2/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_04_10.check-subtree-lcci.h"

namespace LeetCode_04_10 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_04_10Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_04_10Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_04_10::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s1, s2;
  tie(s1, s2) = arguments;

  TreeNode* t1 = buildTreeBySerialize<TreeNode>(s1);
  TreeNode* t2 = buildTreeBySerialize<TreeNode>(s2);

  ASSERT_EQ(solution->checkSubTree(t1, t2), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("1,2,3", "2"), true),
  ParamType(ArgumentType("1,null,2,4", "3,2"), false),
  ParamType(ArgumentType("1,2,3,4,5,6,7,null,8,9", "2,4,5,null,8,9"), true),
  ParamType(ArgumentType("1,2,3,4,5,6,7,null,8,9", "2,4,5,null,8"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_04_10ParamTest, LeetCode_04_10Test, values);

}