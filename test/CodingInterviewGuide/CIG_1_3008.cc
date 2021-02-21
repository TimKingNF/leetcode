//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_3008.hpp"

namespace CIG_1_3008 {

typedef string ArgumentType;
typedef tuple<vector<int>, vector<int>, vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_3008_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_3008_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_3008::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<int> preorder, inorder, postorder;
  tie(preorder, inorder, postorder) = ret;

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(preorder, solution->preorder(root));
  ASSERT_EQ(inorder, solution->inorder(root));
  ASSERT_EQ(postorder, solution->postorder(root));
}

auto values = ::testing::Values(
  ParamType("5,1,4,null,null,3,6",
            ResultType({5,1,4,3,6}, {1,5,3,4,6}, {1,3,6,4,5}))
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_3008_ParamTest, CIG_1_3008_Test, values);

}