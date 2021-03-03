//
// Created by timking.nf@foxmail.com on 2021/2/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "958.check-completeness-of-a-binary-tree.h"

namespace LeetCode958 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode958Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode958Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode958::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->isCompleteTree(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,2,3,4,5,6", true),
  ParamType("1,2,3,4,5,null,7", false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode958ParamTest, LeetCode958Test, values);

}