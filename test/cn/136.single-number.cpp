//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "136.single-number.h"

namespace LeetCode136 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode136Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode136Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode136::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->singleNumber(argument), ret);  // 断言结果
}

ArgumentType p1{2,2,1};
ArgumentType p2{4,1,2,1,2};

ResultType r1 = 1;
ResultType r2 = 4;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode136ParamTest, LeetCode136Test, values);

}