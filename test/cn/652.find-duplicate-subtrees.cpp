//
// Created by timking.nf@foxmail.com on 2020/7/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "652.find-duplicate-subtrees.h"

namespace LeetCode652 {

typedef string ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode652Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode652Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode652::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);
  vector<string> asserted;
  for (auto v : solution->findDuplicateSubtrees(root))
    asserted.push_back(treeSerialize(v));
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType("1,2,3,4,null,2,4,null,null,4", {"2,4", "4"}),
  ParamType("0,0,0,0,null,null,0,0,0,0,0", {"0,0,0", "0"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode652ParamTest, LeetCode652Test, values);

}