//
// Created by timking.nf@foxmail.com on 2020/7/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "108.convert-sorted-array-to-binary-search-tree.h"

namespace LeetCode108 {

typedef vector<int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode108Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode108Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode108::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = solution->sortedArrayToBST(argument);
  ASSERT_EQ(treeSerialize(root), ret);
}

auto values = ::testing::Values(
  ParamType({-10,-3,0,5,9}, "0,-3,9,-10,null,5"),
  ParamType({-10,-3,0,5}, "0,-3,5,-10")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode108ParamTest, LeetCode108Test, values);

}
