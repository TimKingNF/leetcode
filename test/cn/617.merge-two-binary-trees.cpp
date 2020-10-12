//
// Created by timking.nf@foxmail.com on 2020/9/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "617.merge-two-binary-trees.h"

namespace LeetCode617 {

typedef tuple<string, string> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode617Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode617Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode617::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string a1, a2;
  tie(a1, a2) = arguments;
  TreeNode *t1 = buildTreeBySerialize<TreeNode>(a1);
  TreeNode *t2 = buildTreeBySerialize<TreeNode>(a2);

  TreeNode *asserted = solution->mergeTrees(t1, t2);
  ASSERT_EQ(treeSerialize(asserted), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("1,3,2,5", "2,1,3,null,4,null,7"), "3,4,5,5,4,null,7")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode617ParamTest, LeetCode617Test, values);

}