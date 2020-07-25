//
// Created by timking.nf@foxmail.com on 2020/7/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "111.minimum-depth-of-binary-tree.h"

namespace LeetCode111 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode111Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode111Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode111::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);

  ASSERT_EQ(solution->minDepth(root), ret);
}

auto values = ::testing::Values(
  ParamType("3,9,20,null,null,15,7", 2),
  ParamType("3,9,20,null,null,null,7,null,15", 2),
  ParamType("1,2", 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode111ParamTest, LeetCode111Test, values);

}