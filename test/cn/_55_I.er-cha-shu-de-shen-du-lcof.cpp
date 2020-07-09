//
// Created by timking.nf@foxmail.com on 2020/6/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_55_I.er-cha-shu-de-shen-du-lcof.h"

namespace LeetCode_55_I {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode_55_ITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_55_ITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_55_I::Solution();
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
INSTANTIATE_TEST_SUITE_P(LeetCode_55_IParamTest, LeetCode_55_ITest, values);

}