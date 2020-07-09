//
// Created by timking.nf@foxmail.com on 2020/6/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_54.er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof.h"

namespace LeetCode_54 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

class LeetCode_54Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_54Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_54::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  string str;
  int k;
  tie(str, k) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(str);

  ASSERT_EQ(solution->kthLargest(root, k), ret);
}

ArgumentType p1("3,1,4,null,2", 1);
ArgumentType p2("5,3,6,2,4,null,null,1", 3);

auto values = ::testing::Values(
  ParamType(p1, 4),
  ParamType(p2, 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_54ParamTest, LeetCode_54Test, values);

}