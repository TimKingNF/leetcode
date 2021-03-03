//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_5017.hpp"

namespace CIG_1_5017 {

typedef tuple<string, string> ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_5017_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_5017_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_5017::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string str, strlps;
  tie(str, strlps) = arguments;

  // cout << solution->getPalindrome(str, strlps) << endl;
  ASSERT_TRUE(ret.count(solution->getPalindrome(str, strlps)));
}

auto values = ::testing::Values(
  ParamType(ArgumentType("A1B21C", "121"),
            {"AC1B2B1CA", "CA1B2B1AC"}),
  ParamType(ArgumentType("A1BC22DE1F", "1221"),
            {"AF1BCED22DECB1FA"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_5017_ParamTest, CIG_1_5017_Test, values);

}