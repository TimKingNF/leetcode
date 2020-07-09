//
// Created by timking.nf@foxmail.com on 2020/6/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "225.implement-stack-using-queues.h"

namespace LeetCode225 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int null = -1;

class LeetCode225Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode225Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  MyStack* q;
  vector<int> asserts;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "MyStack") {
      q = new MyStack();
      asserts.push_back(null);
    } else if (actions[i] == "push") {
      q->push(inputs[i][0]);
      asserts.push_back(null);
    } else if (actions[i] == "top") {
      asserts.push_back(q->top());
    } else if (actions[i] == "pop") {
      asserts.push_back(q->pop());
    } else if (actions[i] == "empty") {
      asserts.push_back((int) q->empty());
    }
  }

  delete q;
  ASSERT_EQ(asserts, ret);
}

vector<string> p1_0{"MyStack","push","push","pop","top","empty"};
vector<vector<int>> p1_1{{},{1},{2},{},{},{}};
ArgumentType p1(p1_0, p1_1);
ResultType r1{null, null, null, 2, 1, 0};

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode225ParamTest, LeetCode225Test, values);

}