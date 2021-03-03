//
// Created by timking.nf@foxmail.com on 2021/2/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "99.recover-binary-search-tree.h"

namespace LeetCode99 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode99Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode99Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode99::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  solution->recoverTree(root);
  ASSERT_EQ(treeSerialize(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,3,null,null,2", "3,1,null,null,2"),
  ParamType("3,1,4,null,null,2", "2,1,4,null,null,3"),
  ParamType("1,2,null,3", "3,2,null,1")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode99ParamTest, LeetCode99Test, values);

}
