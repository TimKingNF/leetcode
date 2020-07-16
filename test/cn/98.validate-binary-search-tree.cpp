//
// Created by timking.nf@foxmail.com on 2020/7/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "98.validate-binary-search-tree.h"

namespace LeetCode98 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode98Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode98Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode98::Solution();
  ArgumentType argument;
  bool ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);
  ASSERT_EQ(solution->isValidBST(root), ret);

  delete root;
}

auto values = ::testing::Values(
  ParamType("5,1,4,null,null,3,6", false),
  ParamType("2,1,3", true),
  ParamType("10,5,15,null,null,6,20", false),
  ParamType("1,1", false),
  ParamType("", true),
  ParamType("3,1,5,0,2,4,6,null,null,null,3", false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode98ParamTest, LeetCode98Test, values);

}
