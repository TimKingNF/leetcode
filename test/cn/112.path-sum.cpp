//
// Created by timking.nf@foxmail.com on 2020/7/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "112.path-sum.h"

namespace LeetCode112 {

typedef tuple<string, int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode112Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode112Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode112::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string str;
  int sum;
  tie(str, sum) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(str);
  ASSERT_EQ(solution->hasPathSum(root, sum), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("", 0), false),
  ParamType(ArgumentType("5,4,8,11,null,13,4,7,2,null,null,null,1", 22), true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode112ParamTest, LeetCode112Test, values);

}