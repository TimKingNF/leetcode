//
// Created by timking.nf@foxmail.com on 2020/10/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1002.find-common-characters.h"

namespace LeetCode1002 {

typedef vector<string> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1002Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1002Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1002::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->commonChars(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({"bella", "label", "roller"}, {"e", "l", "l"}),
  ParamType({"cool", "lock", "cook"}, {"c", "o"}),
  ParamType({"cool", "app"}, {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1002ParamTest, LeetCode1002Test, values);

}