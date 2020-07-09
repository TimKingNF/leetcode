//
// Created by timking.nf@foxmail.com on 2020/6/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "113.path-sum-ii.h"

namespace LeetCode113 {

typedef pair<vector<int>, vector<int>> TreeOrders;
typedef tuple<TreeOrders, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode113Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode113Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode113::Solution();
  ArgumentType arguments;
  vector<vector<int>> ret;
  tie(arguments, ret) = GetParam();

  TreeOrders orders;
  int sum;
  tie(orders, sum) = arguments;

  TreeNode* root = build_tree<TreeNode, int>(orders.first, orders.second);
  ASSERT_EQ(solution->pathSum(root, sum), ret);

  delete root;
}

vector<int> p1_0_0{5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
vector<int> p1_0_1{7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
TreeOrders p1_0(p1_0_0, p1_0_1);
ArgumentType p1(p1_0, 22);
ResultType r1{{5, 4, 11, 2}, {5, 8, 4, 5}};

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode113ParamTest, LeetCode113Test, values);

}