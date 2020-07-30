//
// Created by timking.nf@foxmail.com on 2020/7/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "705.design-hashset.h"

namespace LeetCode705 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode705Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode705Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  MyHashSet* mySet;
  string asserted;

  for (int i = 0; i < actions.size(); ++i) {
    // cout << actions[i] << endl;
    if (actions[i] == "MyHashSet") {
      mySet = new MyHashSet();
      asserted += "null,";
    } else if (actions[i] == "add") {
      mySet->add(inputs[i][0]);
      asserted += "null,";
    } else if (actions[i] == "remove") {
      mySet->remove(inputs[i][0]);
      asserted += "null,";
    } else if (actions[i] == "contains") {
      asserted += mySet->contains(inputs[i][0]) ? "true," : "false,";
    }
  }

  ASSERT_EQ(asserted.substr(0, asserted.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"MyHashSet","add","add","contains","contains","add","contains","remove","contains"},
                         {{},{1},{2},{1},{3},{2},{2},{2},{2}}),
            "null,null,null,true,false,null,true,null,false"),
  ParamType(ArgumentType({"MyHashSet","add","add","add","add","add","add","add","add","add","add","add","contains"},
                         {{},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{2}}),
            "null,null,null,null,null,null,null,null,null,null,null,null,true"),
  ParamType(ArgumentType({"MyHashSet","add","remove","add","remove","remove","add","add","add","add","remove"},
                         {{},{9},{19},{14},{19},{9},{0},{3},{4},{0},{9}}),
            "null,null,null,null,null,null,null,null,null,null,null")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode705ParamTest, LeetCode705Test, values);

}