//
// Created by timking.nf@foxmail.com on 2020/8/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "208.implement-trie-prefix-tree.h"

namespace LeetCode208 {

typedef tuple<vector<string>, vector<vector<string>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode208Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode208Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<string>> inputs;
  tie(actions, inputs) = arguments;
  Trie* trie;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "Trie") {
      trie = new Trie();
      os << "null,";
    } else if (actions[i] == "insert") {
      trie->insert(inputs[i][0]);
      os << "null,";
    } else if (actions[i] == "search") {
      os << (trie->search(inputs[i][0]) ? "true," : "false,");
    } else if (actions[i] == "startsWith") {
      os << (trie->startsWith(inputs[i][0]) ? "true," : "false,");
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"Trie","insert","search","search","startsWith","insert","search"},
                        {{},{"apple"},{"apple"},{"app"},{"app"},{"app"},{"app"}}),
            "null,null,true,false,true,null,true")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode208ParamTest, LeetCode208Test, values);

}