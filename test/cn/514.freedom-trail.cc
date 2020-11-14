//
// Created by timking.nf@foxmail.com on 2020/11/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "514.freedom-trail.h"

namespace LeetCode514 {

typedef tuple<string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode514Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode514Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode514::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string ring, key;
  tie(ring, key) = arguments;

  ASSERT_EQ(solution->findRotateSteps(ring, key), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("godding", "gd"), 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode514ParamTest, LeetCode514Test, values);

}