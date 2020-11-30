//
// Created by timking.nf@foxmail.com on 2020/11/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "222.count-complete-tree-nodes.h"

namespace LeetCode222 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode222Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode222Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode222::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);

  ASSERT_EQ(solution->countNodes(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,2,3,4,5,6", 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode222ParamTest, LeetCode222Test, values);

}