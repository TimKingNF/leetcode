//
// Created by timking.nf@foxmail.com on 2020/5/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "268.missing-number.h"

namespace LeetCode268 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode268Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode268Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode268::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->missingNumber(argument), ret);  // 断言结果
}

ArgumentType p1{3,0,1};
ArgumentType p2{9,6,4,2,3,5,7,0,1};

auto values = ::testing::Values(
  ParamType(p1, 2),
  ParamType(p2, 8)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode268ParamTest, LeetCode268Test, values);

}
