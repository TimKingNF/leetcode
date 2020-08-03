//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "543.diameter-of-binary-tree.h"

namespace LeetCode543 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode543Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode543Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode543::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();
  
  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);
  ASSERT_EQ(solution->diameterOfBinaryTree(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,2,3,4,5", 3),
  ParamType("1,2,null,4,5,null,null,null,3", 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode543ParamTest, LeetCode543Test, values);

}
