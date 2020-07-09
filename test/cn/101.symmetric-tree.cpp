//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "101.symmetric-tree.h"

namespace LeetCode101 {

typedef pair<vector<int>, vector<int>> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode101Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode101Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode101::Solution();
  ArgumentType argument;
  bool ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = build_tree<TreeNode, int>(argument.first, argument.second);
  ASSERT_EQ(solution->isSymmetric(root), ret);

  delete root;
}

vector<int> p1_0{1, 2, 3, 4, 2, 4, 3};
vector<int> p1_1{3, 2, 4, 1, 4, 2, 3};
ArgumentType p1(p1_0, p1_1);

vector<int> p2_0{1, 2, 3, 2, 3};
vector<int> p2_1{2, 3, 1, 2, 3};
ArgumentType p2(p2_0, p2_1);

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode101ParamTest, LeetCode101Test, values);

}
