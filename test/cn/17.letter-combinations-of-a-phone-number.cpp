//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "17.letter-combinations-of-a-phone-number.h"

namespace LeetCode17 {

typedef string ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode17Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode17Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode17::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType asserted = solution->letterCombinations(argument);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType("", {}),
  ParamType("2", {"a", "b", "c"}),
  ParamType("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}),
  ParamType("32", {"da","db","dc","ea","eb","ec","fa","fb","fc"}),
  ParamType("323", {"dad","dae","daf","dbd","dbe","dbf","dcd","dce",
                    "dcf","ead","eae","eaf","ebd","ebe","ebf","ecd",
                    "ece","ecf","fad","fae","faf","fbd","fbe","fbf",
                    "fcd","fce","fcf"})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode17ParamTest, LeetCode17Test, values);

}