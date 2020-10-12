//
// Created by timking.nf@foxmail.com on 2020/9/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1038.binary-search-tree-to-greater-sum-tree.h"

namespace LeetCode1038 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1038Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1038Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1038::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  TreeNode* assertedTree = solution->bstToGst(root);
  ASSERT_EQ(treeSerialize(assertedTree), ret);
}

auto values = ::testing::Values(
  ParamType("5,2,13,1,null,6", "24,26,13,27,null,19"),
  ParamType("4,1,6,0,2,5,7,null,null,null,3,null,null,null,8",
            "30,36,21,36,35,26,15,null,null,null,33,null,null,null,8")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1038ParamTest, LeetCode1038Test, values);

}