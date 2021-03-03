//
// Created by timking.nf@foxmail.com on 2021/2/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "889.construct-binary-tree-from-preorder-and-postorder-traversal.h"

namespace LeetCode889 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode889Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode889Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode889::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> preorder, postorder;
  tie(preorder, postorder) = arguments;

  TreeNode* root = solution->constructFromPrePost(preorder, postorder);
  ASSERT_TRUE(ret.count(treeSerialize(root)));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,4,5,3,6,7}, {4,5,2,6,7,3,1}),
            {"1,2,3,4,5,6,7"}),
  ParamType(ArgumentType({2,1}, {1,2}),
            {"2,1", "2,null,1"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode889ParamTest, LeetCode889Test, values);

}