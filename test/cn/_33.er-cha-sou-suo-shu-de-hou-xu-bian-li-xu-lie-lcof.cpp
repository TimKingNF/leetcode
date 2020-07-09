//
// Created by timking.nf@foxmail.com on 2020/5/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_33.er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof.h"

namespace LeetCode_33 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_33Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_33Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_33::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->verifyPostorder(argument), ret);  // 断言结果
}

ArgumentType p1{1,6,3,2,5};
ArgumentType p2{1,3,2,6,5};
ArgumentType p3{1,2,5,10,6,9,4,3};
ArgumentType p4{4,6,7,5};

auto values = ::testing::Values(
  ParamType(p1, false),
  ParamType(p2, true),
  ParamType(p3, false),
  ParamType(p4, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_33ParamTest, LeetCode_33Test, values);

}