//
// Created by timking.nf@foxmail.com on 2021/1/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "303.range-sum-query-immutable.h"

namespace LeetCode303 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode303Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode303Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  NumArray* numArray;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "NumArray") {
      numArray = new NumArray(inputs[i]);
      os << "null,";
    } else if (actions[i] == "sumRange") {
      int v = numArray->sumRange(inputs[i][0], inputs[i][1]);
      os << v << ",";
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"NumArray", "sumRange", "sumRange", "sumRange"},
                         {{-2, 0, 3, -5, 2, -1}, {0,2}, {2,5}, {0,5}}),
            "null,1,-1,-3")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode303ParamTest, LeetCode303Test, values);

}