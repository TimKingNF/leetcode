//
// Created by timking.nf@foxmail.com on 2020/12/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "860.lemonade-change.h"

namespace LeetCode860 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode860Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode860Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode860::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->lemonadeChange(argument), ret);
}

auto values = ::testing::Values(
  ParamType({5,5,5,10,20}, true),
  ParamType({5,5,10}, true),
  ParamType({10,10}, false),
  ParamType({5,5,10,10,20}, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode860ParamTest, LeetCode860Test, values);

}