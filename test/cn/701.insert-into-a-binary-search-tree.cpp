//
// Created by timking.nf@foxmail.com on 2020/8/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "701.insert-into-a-binary-search-tree.h"

namespace LeetCode701 {

typedef tuple<string, int> ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode701Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode701Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode701::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int val;
  tie(args, val) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(args);
  TreeNode* resultRoot = solution->insertIntoBST(root, val);

  ASSERT_TRUE(ret.count(treeSerialize(resultRoot)));
}

auto values = ::testing::Values(
  ParamType(ArgumentType("4,2,7,1,3", 5), {"4,2,7,1,3,5",
                                           "5,2,7,1,3,null,null,null,null,null,4"}),
  ParamType(ArgumentType("", 5), {"5"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode701ParamTest, LeetCode701Test, values);

}