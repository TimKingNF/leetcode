//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "380.insert-delete-getrandom-o1.h"

namespace LeetCode380 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode380Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode380Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  RandomizedSet* mySet;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    // cout << actions[i] << endl;
    if (actions[i] == "RandomizedSet") {
      mySet = new RandomizedSet();
      os << "null,";
    } else if (actions[i] == "insert") {
      os << (mySet->insert(inputs[i][0]) ? "true," : "false,");
    } else if (actions[i] == "remove") {
      os << (mySet->remove(inputs[i][0]) ? "true," : "false,");
    } else if (actions[i] == "getRandom") {
      os << mySet->getRandom() << ",";
    }
  }

  string asserted = os.str();
  ASSERT_EQ(asserted.substr(0, asserted.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"},
                         {{},{1},{2},{2},{},{1},{2}}),
            "null,true,false,true,2,true,false,2"),
  ParamType(ArgumentType({"RandomizedSet","insert","insert","remove","insert","remove","getRandom"},
                         {{},{0},{1},{0},{2},{1},{}}),
            "null,true,true,true,true,true,2")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode380ParamTest, LeetCode380Test, values);

}