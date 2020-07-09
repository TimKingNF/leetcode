//
// Created by timking.nf@foxmail.com on 2020/6/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "104.maximum-depth-of-binary-tree.h"

namespace LeetCode104 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode104Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode104Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode104::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);

  ASSERT_EQ(solution->maxDepth(root), ret);
}

ArgumentType p1 = "3,9,20,null,null,15,7";
ArgumentType p2 = "3,9,20,null,null,null,7,null,15";

auto values = ::testing::Values(
  ParamType(p1, 3),
  ParamType(p2, 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode104ParamTest, LeetCode104Test, values);

}