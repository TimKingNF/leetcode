//
// Created by timking.nf@foxmail.com on 2020/7/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "145.binary-tree-postorder-traversal.h"

namespace LeetCode145 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode145Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode145Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode145::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);
  ASSERT_EQ(solution->postorderTraversal(root), ret);
}

auto values = ::testing::Values(
  ParamType("", {}),
  ParamType("5,1,4,null,null,3,6", {1,3,6,4,5}),
  ParamType("2,1,3", {1,3,2}),
  ParamType("10,5,15,null,null,6,20", {5,6,20,15,10}),
  ParamType("1,1", {1,1}),
  ParamType("3,1,5,0,2,4,6,null,null,null,3", {0,3,2,1,4,6,5,3})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode145ParamTest, LeetCode145Test, values);

}