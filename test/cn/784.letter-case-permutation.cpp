//
// Created by timking.nf@foxmail.com on 2020/7/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "784.letter-case-permutation.h"

namespace LeetCode784 {

typedef string ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode784Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode784Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode784::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<string> asserted = solution->letterCasePermutation(argument);
  ASSERT_TRUE(vector_unordered_cmp<string>(asserted, ret));  // 断言结果
}

ArgumentType p1 = "a1b2";
ResultType r1 = {"a1b2", "a1B2", "A1b2", "A1B2"};

ArgumentType p2 = "3z4";
ResultType r2 = {"3z4", "3Z4"};

ArgumentType p3 = "12345";
ResultType r3 = {"12345"};

ArgumentType p4 = "mQe";
ResultType r4 = {"mqe","mqE","mQe","mQE","Mqe","MqE","MQe","MQE"};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3),
  ParamType(p4, r4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode784ParamTest, LeetCode784Test, values);

}