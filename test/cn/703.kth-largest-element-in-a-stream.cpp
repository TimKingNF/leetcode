//
// Created by timking.nf@foxmail.com on 2020/8/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "703.kth-largest-element-in-a-stream.h"

namespace LeetCode703 {

typedef tuple<vector<string>, vector<pair<int, vector<int>>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode703Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode703Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<pair<int, vector<int>>> inputs;
  tie(actions, inputs) = arguments;
  KthLargest* cls;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    // cout << actions[i] << endl;
    if (actions[i] == "KthLargest") {
      cls = new KthLargest(inputs[i].first, inputs[i].second);
      os << "null,";
    } else if (actions[i] == "add") {
      os << cls->add(inputs[i].first) << ",";
    }
  }

  string asserted = os.str();
  ASSERT_EQ(asserted.substr(0, asserted.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"KthLargest","add","add","add","add","add"},
                         {{3, {4,5,8,2}},
                          {3, {}},
                          {5, {}},
                          {10, {}},
                          {9, {}},
                          {4, {}}}),
            "null,4,5,5,8,8")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode703ParamTest, LeetCode703Test, values);

}