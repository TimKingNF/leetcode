//
// Created by timking.nf@foxmail.com on 2020/6/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_49.chou-shu-lcof.h"

namespace LeetCode_49 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_49Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_49Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_49::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->nthUglyNumber(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(10, 12)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_49ParamTest, LeetCode_49Test, values);

}