//
// Created by timking.nf@foxmail.com on 2020/10/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "783.minimum-distance-between-bst-nodes.h"

namespace LeetCode783 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode783Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode783Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode783::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode *root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->minDiffInBST(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,null,3,2", 1),
  ParamType("1,null,5,3", 2),
  ParamType("4,2,6,1,3", 1),
  ParamType("27,null,34,null,58,50,null,44,null,null,null", 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode783ParamTest, LeetCode783Test, values);

}