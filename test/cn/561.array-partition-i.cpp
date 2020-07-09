//
// Created by timking.nf@foxmail.com on 2020/5/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "561.array-partition-i.h"

namespace LeetCode561 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode561Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode561Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode561::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->arrayPairSum(argument), ret);  // 断言结果
}

ArgumentType p1{1,4,3,2};
ArgumentType p2{6214, -2290, 2833, -7908};

auto values = ::testing::Values(
  ParamType(p1, 4),
  ParamType(p2, -5075)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode561ParamTest, LeetCode561Test, values);

}
