//
// Created by timking.nf@foxmail.com on 2020/9/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "637.average-of-levels-in-binary-tree.h"

namespace LeetCode637 {

typedef string ArgumentType;
typedef vector<double> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode637Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode637Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode637::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->averageOfLevels(root), ret);
}

auto values = ::testing::Values(
  ParamType("3,9,20,null,null,15,7", {3, 14.5, 11})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode637ParamTest, LeetCode637Test, values);

}