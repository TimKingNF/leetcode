//
// Created by timking.nf@foxmail.com on 2020/10/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "925.long-pressed-name.h"

namespace LeetCode925 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode925Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode925Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode925::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string name, typed;
  tie(name, typed) = arguments;

  ASSERT_EQ(solution->isLongPressedName(name, typed), ret);
}

auto values = ::testing::Values(
  ParamType({"alex", "aaleex"}, true),
  ParamType({"saeed", "ssaaedd"}, false),
  ParamType({"leelee", "lleeelee"}, true),
  ParamType({"laiden", "laiden"}, true),
  ParamType({"pyplrz", "ppyypllr"}, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode925ParamTest, LeetCode925Test, values);

}