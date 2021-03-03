//
// Created by timking.nf@foxmail.com on 2021/2/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_04_05.legal-binary-search-tree-lcci.h"

namespace LeetCode_04_05 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_04_05Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_04_05Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_04_05::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);

  ASSERT_EQ(solution->isValidBST(root), ret);
}

auto values = ::testing::Values(
  ParamType("2,1,3", true),
  ParamType("5,1,4,null,null,3,6", false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_04_05ParamTest, LeetCode_04_05Test, values);

}