//
// Created by timking.nf@foxmail.com on 2020/5/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_50.di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof.h"

namespace LeetCode_50 {

typedef string ArgumentType;
typedef char ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_50Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_50Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_50::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->firstUniqChar(argument), ret);  // 断言结果
}

ArgumentType p1 = "abaccdeff";
ArgumentType p2 = "";

ResultType r1 = 'b';
ResultType r2 = ' ';

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_50ParamTest, LeetCode_50Test, values);

}