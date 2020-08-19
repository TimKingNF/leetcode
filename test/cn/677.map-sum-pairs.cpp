//
// Created by timking.nf@foxmail.com on 2020/8/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "677.map-sum-pairs.h"

namespace LeetCode677 {

typedef tuple<vector<string>, vector<pair<string, int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode677Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode677Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<pair<string, int>> inputs;
  tie(actions, inputs) = arguments;
  MapSum* mapSum;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "MapSum") {
      mapSum = new MapSum();
      os << "null,";
    } else if (actions[i] == "insert") {
      mapSum->insert(inputs[i].first, inputs[i].second);
      os << "null,";
    } else if (actions[i] == "sum") {
      os << mapSum->sum(inputs[i].first) << ",";
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"MapSum", "insert", "sum", "insert", "sum"},
                         {{}, {"apple",3}, {"ap", 0}, {"app",2}, {"ap", 0}}),
            "null,null,3,null,5"),
  ParamType(ArgumentType({"MapSum", "insert", "insert", "sum"},
                         {{}, {"apple",3}, {"apple", 2}, {"ap", 0}}),
            "null,null,null,2")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode677ParamTest, LeetCode677Test, values);

}