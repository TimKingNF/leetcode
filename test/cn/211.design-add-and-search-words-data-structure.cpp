//
// Created by timking.nf@foxmail.com on 2020/8/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "211.design-add-and-search-words-data-structure.h"

namespace LeetCode211 {

typedef tuple<vector<string>, vector<vector<string>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode211Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode211Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<string>> inputs;
  tie(actions, inputs) = arguments;
  WordDictionary* wordDictionary;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "WordDictionary") {
      wordDictionary = new WordDictionary();
      os << "null,";
    } else if (actions[i] == "addWord") {
      wordDictionary->addWord(inputs[i][0]);
      os << "null,";
    } else if (actions[i] == "search") {
      os << (wordDictionary->search(inputs[i][0]) ? "true," : "false,");
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"WordDictionary","addWord","addWord","addWord","search","search","search","search"},
                         {{},{"bad"},{"dad"},{"mad"},{"pad"},{"bad"},{".ad"},{"b.."}}),
            "null,null,null,null,false,true,true,true"),
  ParamType(ArgumentType({"WordDictionary","addWord","search","search","search"},
                         {{},{"bad"},{"ba"},{"mad"},{"..b"}}),
            "null,null,false,false,false")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode211ParamTest, LeetCode211Test, values);

}