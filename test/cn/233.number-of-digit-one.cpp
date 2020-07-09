//
// Created by timking.nf@foxmail.com on 2020/6/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "233.number-of-digit-one.h"

namespace LeetCode233 {

typedef int ArgumentType;
typedef tuple<ArgumentType, int> ParamType;

class LeetCode233Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode233Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode233::Solution();
  ArgumentType arguments;
  int ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->countDigitOne(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(12, 5),
  ParamType(13, 6),
  ParamType(1410065408, 1737167499),
  ParamType(99, 20)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode233ParamTest, LeetCode233Test, values);

}