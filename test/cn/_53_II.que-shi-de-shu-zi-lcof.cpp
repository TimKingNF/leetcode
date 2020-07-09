//
// Created by timking.nf@foxmail.com on 2020/6/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_53_II.que-shi-de-shu-zi-lcof.h"

namespace LeetCode_53_II {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_53_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_53_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_53_II::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->missingNumber(argument), ret);  // 断言结果
}

ArgumentType p1{0,1,3};
ArgumentType p2{0,1,2,3,4,5,6,7,9};

auto values = ::testing::Values(
  ParamType(p1, 2),
  ParamType(p2, 8)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_53_IIParamTest, LeetCode_53_IITest, values);

}
