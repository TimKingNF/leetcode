//
// Created by timking.nf@foxmail.com on 2020/10/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "381.insert-delete-getrandom-o1-duplicates-allowed.h"

namespace LeetCode381 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode381Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode381Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  RandomizedCollection* collection;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "RandomizedCollection") {
      collection = new RandomizedCollection();
      os << "null,";
    } else if (actions[i] == "insert") {
      collection->insert(inputs[i][0]);
      os << "null,";
    } else if (actions[i] == "getRandom") {
      os << collection->getRandom() << ",";
    } else if (actions[i] == "remove") {
      collection->remove(inputs[i][0]);
      os << "null,";
    }
  }

  string oss = os.str();
  string asserted = oss.substr(0, oss.size()-1);
  ASSERT_TRUE(ret.count(asserted));  // 返回其中一种结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"},
                         {{},{1},{1},{2},{},{1},{}}),
            {
              "null,null,null,null,1,null,1",
              "null,null,null,null,1,null,2",
              "null,null,null,null,2,null,1",
              "null,null,null,null,2,null,2"
            })
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode381ParamTest, LeetCode381Test, values);

}