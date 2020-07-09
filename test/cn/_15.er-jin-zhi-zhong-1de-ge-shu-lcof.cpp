//
// Created by timking.nf@foxmail.com on 2020/5/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_15.er-jin-zhi-zhong-1de-ge-shu-lcof.h"

namespace LeetCode_15 {

typedef uint32_t ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_15Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_15Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_15::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->hammingWeight(argument), ret);  // 断言结果
}

ArgumentType p1 = 9;

auto values = ::testing::Values(
  ParamType(p1, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_15ParamTest, LeetCode_15Test, values);

}

