//
// Created by timking.nf@foxmail.com on 2020/8/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "474.ones-and-zeroes.h"

namespace LeetCode474 {

typedef tuple<vector<string>, int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode474Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode474Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode474::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> strs;
  int m, n;
  tie(strs, m, n) = arguments;

  ASSERT_EQ(solution->findMaxForm(strs, m, n), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"10", "0001", "111001", "1", "0"}, 5, 3), 4),
  ParamType(ArgumentType({"10", "0", "1"}, 1, 1), 2),
  ParamType(ArgumentType({"1", "0", "00"}, 2, 1), 2),
  ParamType(ArgumentType({"111", "1000", "1000", "1000"}, 9, 3), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode474ParamTest, LeetCode474Test, values);

}