//
// Created by timking.nf@foxmail.com on 2020/9/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "171.excel-sheet-column-number.h"

namespace LeetCode171 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode171Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode171Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode171::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->titleToNumber(argument), ret);
}

auto values = ::testing::Values(
  ParamType("A", 1),
  ParamType("ZY", 701),
  ParamType("AB", 28)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode171ParamTest, LeetCode171Test, values);

}