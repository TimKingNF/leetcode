//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_3018.hpp"

namespace CIG_1_3018 {

typedef vector<int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_3018_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_3018_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_3018::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(treeSerialize(solution->postArrayToBST(argument)), ret);
}

auto values = ::testing::Values(
  ParamType({2,1,3,6,5,7,4}, "4,3,7,1,null,5,null,null,2,null,6"),
  ParamType({2,1,3,5,0,7,4}, "null")  // 无法构成 BST 树
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_3018_ParamTest, CIG_1_3018_Test, values);

}