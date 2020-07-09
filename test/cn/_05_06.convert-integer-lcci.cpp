//
// Created by timking.nf@foxmail.com on 2020/7/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_05_06.convert-integer-lcci.h"

namespace LeetCode_05_06 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_05_06Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_05_06Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_05_06::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int x, y;
  tie(x, y) = arguments;

  ASSERT_EQ(solution->convertInteger(x, y), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(tuple<int, int>(1, 4), 2),
  ParamType(tuple<int, int>(29, 15), 2),
  ParamType(tuple<int, int>(1, 2), 2),
  ParamType(tuple<int, int>(826966453, -729934991), 14)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_05_06ParamTest, LeetCode_05_06Test, values);

}