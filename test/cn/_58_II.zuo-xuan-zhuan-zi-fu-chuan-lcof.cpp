//
// Created by timking.nf@foxmail.com on 2020/6/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_58_II.zuo-xuan-zhuan-zi-fu-chuan-lcof.h"

namespace LeetCode_58_II {

typedef tuple<string, int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_58_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_58_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_58_II::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  string s;
  int n;
  tie(s, n) = arguments;

  ASSERT_EQ(solution->reverseLeftWords(s, n), ret);
}

string p1_0 = "abcdefg";
ArgumentType p1(p1_0, 2);
ResultType r1 = "cdefgab";

string p2_0 = "lrloseumgh";
ArgumentType p2(p2_0, 6);
ResultType r2 = "umghlrlose";

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_58_IIParamTest, LeetCode_58_IITest, values);

}
