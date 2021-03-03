//
// Created by timking.nf@foxmail.com on 2021/2/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1008.construct-binary-search-tree-from-preorder-traversal.h"

namespace LeetCode1008 {

typedef vector<int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1008Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1008Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1008::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = solution->bstFromPreorder(argument);
  ASSERT_EQ(treeSerialize(root), ret);
}

auto values = ::testing::Values(
  ParamType({8,5,1,7,10,12}, "8,5,10,1,7,null,12")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1008ParamTest, LeetCode1008Test, values);

}