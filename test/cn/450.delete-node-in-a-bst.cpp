//
// Created by timking.nf@foxmail.com on 2020/8/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "450.delete-node-in-a-bst.h"

namespace LeetCode450 {

typedef tuple<string, int> ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode450Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode450Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode450::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int key;
  tie(args, key) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(args);
  TreeNode* resultRoot = solution->deleteNode(root, key);
  // cout << treeSerialize(resultRoot) << endl;
  ASSERT_TRUE(ret.count(treeSerialize(resultRoot)));
}

auto values = ::testing::Values(
  ParamType(ArgumentType("1", 1), {"null"}),
  ParamType(ArgumentType("1,null,2", 2), {"1"}),
  ParamType(ArgumentType("1,null,2", 1), {"2"}),
  ParamType(ArgumentType("5,3,6,2,4,null,7", 3), {"5,4,6,2,null,null,7",
                                                  "5,2,6,null,4,null,7"}),
  ParamType(ArgumentType("5,3,6,2,4,null,7", 6), {"5,3,7,2,4"}),
  ParamType(ArgumentType("5,3,6,2,4,null,7", 5), {"4,3,6,2,null,null,7",
                                                  "6,3,7,2,4"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode450ParamTest, LeetCode450Test, values);

}