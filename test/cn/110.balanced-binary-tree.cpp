//
// Created by timking.nf@foxmail.com on 2020/6/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "110.balanced-binary-tree.h"

namespace LeetCode110 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode110Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode110Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode110::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);

  ASSERT_EQ(solution->isBalanced(root), ret);
}

ArgumentType p1 = "3,9,20,null,null,15,7";
ArgumentType p2 = "1,2,2,3,3,null,null,4,4";

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode110ParamTest, LeetCode110Test, values);

}