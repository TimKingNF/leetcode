//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_3029.hpp"

namespace CIG_1_3029 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_3029_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_3029_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_3029::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> preOrder, inOrder;
  tie(preOrder, inOrder) = arguments;

  ASSERT_EQ(solution->getPostOrder(preOrder, inOrder), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,4,5,3,6,7}, {4,2,5,1,6,3,7}), {4,5,2,6,7,3,1}),
  ParamType(ArgumentType({3,9,20,15,7}, {9,3,15,20,7}), {9,15,7,20,3})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_3029_ParamTest, CIG_1_3029_Test, values);

}