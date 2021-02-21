//
// Created by timking.nf@foxmail.com on 2021/2/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "545.boundary-of-binary-tree.h"

namespace LeetCode545 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode545Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode545Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode545::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  auto root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->boundaryOfBinaryTree(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,null,2,3,4", {1,3,4,2}),
  ParamType("1,2,null,3,4", {1,2,3,4}),
  ParamType("1,2,3,4,5,6,null,null,null,7,8,9,10", {1,2,4,7,8,9,10,6,3}),
  ParamType("1,2,3,null,4,5,6,7,8,9,10,null,null,null,null,null,11,12,null,null,null,13,14,15,16",
            {1,2,4,7,13,14,15,16,10,6,3})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode545ParamTest, LeetCode545Test, values);

}