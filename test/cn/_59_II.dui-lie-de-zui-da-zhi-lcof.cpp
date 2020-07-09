//
// Created by timking.nf@foxmail.com on 2020/6/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_59_II.dui-lie-de-zui-da-zhi-lcof.h"

namespace LeetCode_59_II {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int null = -1;

class LeetCode_59_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_59_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  MaxQueue* q;
  vector<int> asserts;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "MaxQueue") {
      q = new MaxQueue();
      asserts.push_back(null);
    } else if (actions[i] == "push_back") {
      q->push_back(inputs[i][0]);
      asserts.push_back(null);
    } else if (actions[i] == "max_value") {
      asserts.push_back(q->max_value());
    } else if (actions[i] == "pop_front") {
      asserts.push_back(q->pop_front());
    }
  }

  delete q;
  ASSERT_EQ(asserts, ret);
}

vector<string> p1_0{"MaxQueue","push_back","push_back","max_value","pop_front","max_value"};
vector<vector<int>> p1_1{{},{1},{2},{},{},{}};
ArgumentType p1(p1_0, p1_1);
ResultType r1{null, null, null, 2, 1, 2};

vector<string> p2_0{"MaxQueue","pop_front","max_value"};
vector<vector<int>> p2_1{{},{},{}};
ArgumentType p2(p2_0, p2_1);
ResultType r2{null, null, null};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_59_IIParamTest, LeetCode_59_IITest, values);

}
