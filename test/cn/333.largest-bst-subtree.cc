//
// Created by timking.nf@foxmail.com on 2021/2/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "333.largest-bst-subtree.h"

namespace LeetCode333 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode333Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode333Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode333::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->largestBSTSubtree(root), ret);
}

auto values = ::testing::Values(
  ParamType("10,5,15,1,8,null,7", 3),
  ParamType("4,2,7,2,3,5,null,2,null,null,null,null,null,1", 2),
  ParamType("6,1,12,0,3,10,13,null,null,null,null,4,14,20,16,2,5,11,15", 7),
  ParamType("6,-1,4,1,null,9,null,0,3,8,10", 3)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode333ParamTest, LeetCode333Test, values);

}