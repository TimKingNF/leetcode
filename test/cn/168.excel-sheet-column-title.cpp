//
// Created by timking.nf@foxmail.com on 2020/9/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "168.excel-sheet-column-title.h"

namespace LeetCode168 {

typedef int ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode168Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode168Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode168::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->convertToTitle(argument), ret);
}

auto values = ::testing::Values(
  ParamType(1, "A"),
  ParamType(28, "AB"),
  ParamType(701, "ZY"),
  ParamType(108000, "FCSV")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode168ParamTest, LeetCode168Test, values);

}