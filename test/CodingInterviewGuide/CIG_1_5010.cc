//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_5010.hpp"

namespace CIG_1_5010 {

typedef tuple<vector<string>, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_5010_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_5010_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_5010::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> args;
  string str;
  tie(args, str) = arguments;
  vector<string*> strs(args.size());

  for (int i = 0; i < args.size(); ++i) {
    strs[i] = (args[i] == "null" ? nullptr : &args[i]);
  }

  ASSERT_EQ(solution->getIndex(strs, &str), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"null","a","null","a","null","b","null","c"}, "a"), 1),
  ParamType(ArgumentType({"null","a","null","a","null","b","null","c"}, "null"), -1),
  ParamType(ArgumentType({"null","a","null","a","null","b","null","c"}, "d"), -1),
  ParamType(ArgumentType({"null","a","null","a","null","b","null","c"}, "c"), 7)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_5010_ParamTest, CIG_1_5010_Test, values);

}