//
// Created by timking.nf@foxmail.com on 2020/5/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_32_II.cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof.h"

namespace LeetCode_32_II {

typedef string ArgumentType;
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
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  ASSERT_EQ(solution->levelOrder(root), ret);
}

auto values = ::testing::Values(
  ParamType("3,9,20,null,null,15,7", {{3}, {9, 20}, {15, 7}}),
  ParamType("1", {{1}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_32_IIParamTest, LeetCode_32_IITest, values);

}
