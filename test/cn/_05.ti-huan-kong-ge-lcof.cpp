//
// Created by timking.nf@foxmail.com on 2020/5/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_05.ti-huan-kong-ge-lcof.h"

namespace LeetCode_05 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_05Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_05Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_05::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->replaceSpace(argument), ret);  // 断言结果
}

ArgumentType p1 = "We are happy.";

ResultType r1 = "We%20are%20happy.";

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_05ParamTest, LeetCode_05Test, values);

}
