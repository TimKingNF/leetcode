//
// Created by timking.nf@foxmail.com on 2020/7/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "706.design-hashmap.h"

namespace LeetCode706 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode706Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode706Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  MyHashMap* myMap;
  string asserted;

  for (int i = 0; i < actions.size(); ++i) {
    // cout << actions[i] << endl;
    if (actions[i] == "MyHashMap") {
      myMap = new MyHashMap();
      asserted += "null,";
    } else if (actions[i] == "put") {
      myMap->put(inputs[i][0], inputs[i][1]);
      asserted += "null,";
    } else if (actions[i] == "remove") {
      myMap->remove(inputs[i][0]);
      asserted += "null,";
    } else if (actions[i] == "get") {
      asserted += to_string(myMap->get(inputs[i][0])) + ",";
    }
  }

  ASSERT_EQ(asserted.substr(0, asserted.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"MyHashMap","put","put","get","get","put","get", "remove", "get"},
                         {{},{1,1},{2,2},{1},{3},{2,1},{2},{2},{2}}),
            "null,null,null,1,-1,null,1,null,-1")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode706ParamTest, LeetCode706Test, values);

}