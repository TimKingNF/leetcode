//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_26.shu-de-zi-jie-gou-lcof.h"

namespace LeetCode_26 {

typedef pair<vector<int>, vector<int>> TreeOrders;
typedef tuple<TreeOrders , TreeOrders> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_26Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_26Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_26::Solution();
  ArgumentType arguments;
  bool ret;
  tie(arguments, ret) = GetParam();

  TreeOrders firstOrders, secondOrders;
  tie(firstOrders, secondOrders) = arguments;
  TreeNode* first = build_tree<TreeNode, int>(firstOrders.first, firstOrders.second);
  TreeNode* second = build_tree<TreeNode, int>(secondOrders.first, secondOrders.second);

  ASSERT_EQ(solution->isSubStructure(first, second), ret);

  delete first;
  delete second;
}

TreeOrders p1_0({1, 2, 3}, {2, 1, 3});
TreeOrders p1_1({3, 1}, {1, 3});
ArgumentType p1(p1_0, p1_1);

TreeOrders p2_0({3, 4, 5, 1, 2}, {5, 4, 1, 3, 2});
TreeOrders p2_1({4, 1}, {4, 1});
ArgumentType p2(p2_0, p2_1);

auto values = ::testing::Values(
  ParamType(p1, false),
  ParamType(p2, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_26ParamTest, LeetCode_26Test, values);

}
