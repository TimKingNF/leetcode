//
// Created by timking.nf@foxmail.com on 2020/8/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "173.binary-search-tree-iterator.h"

namespace LeetCode173 {

typedef tuple<vector<string>, vector<vector<string>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode173Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode173Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<string>> inputs;
  tie(actions, inputs) = arguments;
  BSTIterator* iterator;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "BSTIterator") {
      TreeNode* root = buildTreeBySerialize<TreeNode, convert>(inputs[i][0]);
      iterator = new BSTIterator(root);
      os << "null,";
    } else if (actions[i] == "next") {
      os << iterator->next() << ",";
    } else if (actions[i] == "hasNext") {
      os << (iterator->hasNext() ? "true," : "false,");
    }
  }

  string asserted = os.str();
  ASSERT_EQ(asserted.substr(0, asserted.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"},
                         {{"7,3,15,null,null,9,20"},{},{},{},{},{},{},{},{},{}}),
            "null,3,7,true,9,true,15,true,20,false")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode173ParamTest, LeetCode173Test, values);

}