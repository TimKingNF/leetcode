//
// Created by timking.nf@foxmail.com on 2020/7/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "752.open-the-lock.h"

namespace LeetCode752 {

typedef tuple<vector<string>, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode752Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode752Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode752::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> deadends;
  string target;
  tie(deadends, target) = arguments;

  ASSERT_EQ(solution->openLock(deadends, target), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"0000"}, "8888"), -1),
  ParamType(ArgumentType({"8888"}, "0009"), 1),
  ParamType(ArgumentType({"8887","8889","8878","8898","8788","8988","7888","9888"},
                         "8888"), -1),
  ParamType(ArgumentType({"0100", "0001"}, "0101"), 4),
  ParamType(ArgumentType({"0201","0101","0102","1212","2002"}, "0202"), 6)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode752ParamTest, LeetCode752Test, values);

}