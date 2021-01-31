//
// Created by timking.nf@foxmail.com on 2021/1/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "399.evaluate-division.h"

namespace LeetCode399 {

typedef tuple<vector<vector<string>>, vector<double>, vector<vector<string>>> ArgumentType;
typedef vector<double> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode399Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode399Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode399::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<string>> equations;
  vector<double> values;
  vector<vector<string>> queries;
  tie(equations, values, queries) = arguments;

  ResultType asserted = solution->calcEquation(equations, values, queries);
  ASSERT_EQ(asserted.size(), ret.size());
  // vector_print(asserted);
  for (int i = 0; i < ret.size(); ++i) {
    ASSERT_DOUBLE_EQ(asserted[i], ret[i]);
  }
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{"a","b"},{"b","c"}}, {2.0, 3.0},
                         {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}}),
            {6.00000,0.50000,-1.00000,1.00000,-1.00000}),
  ParamType(ArgumentType({{"a","b"},{"b","c"},{"bc","cd"}}, {1.5,2.5,5.0},
                            {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}}),
            {3.75000,0.40000,5.00000,0.20000}),
  ParamType(ArgumentType({{"a","b"}}, {0.5},
                         {{"a","b"},{"b","a"},{"a","c"},{"x","y"}}),
           {0.50000,2.00000,-1.00000,-1.00000}),
  ParamType(ArgumentType({{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}},
                        {3.0,4.0,5.0,6.0},
            {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}}),
            {360.00000,0.00833333333333333333,20.00000,1.00000,-1.00000,-1.00000})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode399ParamTest, LeetCode399Test, values);

}