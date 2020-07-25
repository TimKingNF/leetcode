//
// Created by timking.nf@foxmail.com on 2020/7/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "106.construct-binary-tree-from-inorder-and-postorder-traversal.h"

namespace LeetCode106 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode106Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode106Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode106::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> inorder, postorder;
  tie(inorder, postorder) = arguments;

  TreeNode* tree = solution->buildTree(inorder, postorder);
  ASSERT_EQ(treeSerialize<TreeNode>(tree), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({9,3,15,20,7}, {9,15,7,20,3}), "3,9,20,null,null,15,7")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode106ParamTest, LeetCode106Test, values);

}