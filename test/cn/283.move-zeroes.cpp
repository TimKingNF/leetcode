//
// Created by timking.nf@foxmail.com on 2020/5/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "283.move-zeroes.h"

namespace LeetCode283 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode283Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode283Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode283::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->moveZeroes(argument);
  ASSERT_EQ(argument, ret);  // 断言结果
}

ArgumentType p1{0,1,0,3,12};
ArgumentType p2{0};
ArgumentType p3{0,0};
ArgumentType p4{1,0};

ResultType r1{1,3,12,0,0};
ResultType r2{0};
ResultType r3{0,0};
ResultType r4{1,0};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3),
  ParamType(p4, r4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode283ParamTest, LeetCode283Test, values);

}
