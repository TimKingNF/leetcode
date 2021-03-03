//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_3009.hpp"

namespace CIG_1_3009 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_3009_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_3009_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_3009::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string arg;
  int sum;
  tie(arg, sum) = arguments;

  TreeNode *root = buildTreeBySerialize<TreeNode>(arg);
  ASSERT_EQ(solution->getMaxLength(root, sum), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("-3,3,-9,1,0,2,1,null,null,1,6", 6), 4),
  ParamType(ArgumentType("-3,3,-9,1,0,2,1,null,null,1,6", -9), 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_3009_ParamTest, CIG_1_3009_Test, values);

}