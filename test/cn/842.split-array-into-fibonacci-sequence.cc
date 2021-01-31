//
// Created by timking.nf@foxmail.com on 2020/12/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "842.split-array-into-fibonacci-sequence.h"

namespace LeetCode842 {

typedef string ArgumentType;
typedef set<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode842Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode842Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode842::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<int> asserted = solution->splitIntoFibonacci(argument);
  ASSERT_TRUE(ret.count(asserted));
}

auto values = ::testing::Values(
  ParamType("123456579", {{123,456,579}}),
  ParamType("11235813", {{1,1,2,3,5,8,13}}),
  ParamType("112358130", {{}}),
  ParamType("0123", {{}}),
  ParamType("1101111", {{110, 1, 111}, {11,0,11,11}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode842ParamTest, LeetCode842Test, values);

}