//
// Created by timking.nf@foxmail.com on 2020/5/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_32_II.cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof.h"

namespace LeetCode_32_II {

typedef pair<vector<int>, vector<int>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_32_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_32_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_32_II::Solution();
  ArgumentType argument;
  vector<vector<int>> ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = build_tree<TreeNode, int>(argument.first, argument.second);
  ASSERT_EQ(solution->levelOrder(root), ret);

  delete root;
}

vector<int> p1_0{3, 9, 20, 15, 7};
vector<int> p1_1{9, 3, 15, 20, 7};
ArgumentType p1(p1_0, p1_1);
ResultType r1{{3}, {9, 20}, {15, 7}};

vector<int> p2_0{1};
vector<int> p2_1{1};
ArgumentType p2(p2_0, p2_1);
ResultType r2{{1}};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_32_IIParamTest, LeetCode_32_IITest, values);

}
