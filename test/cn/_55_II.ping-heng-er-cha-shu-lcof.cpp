//
// Created by timking.nf@foxmail.com on 2020/6/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_55_II.ping-heng-er-cha-shu-lcof.h"

namespace LeetCode_55_II {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode_55_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_55_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_55_II::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(argument);

  ASSERT_EQ(solution->isBalanced(root), ret);
}

ArgumentType p1 = "3,9,20,null,null,15,7";
ArgumentType p2 = "1,2,2,3,3,null,null,4,4";

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_55_IIParamTest, LeetCode_55_IITest, values);

}