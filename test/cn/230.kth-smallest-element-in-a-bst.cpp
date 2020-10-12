//
// Created by timking.nf@foxmail.com on 2020/8/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "230.kth-smallest-element-in-a-bst.h"

namespace LeetCode230 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode230Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode230Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode230::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int k;
  tie(args, k) = arguments;
  TreeNode* root = buildTreeBySerialize<TreeNode, convert_stoi>(args);

  ASSERT_EQ(solution->kthSmallest(root, k), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("3,1,4,null,2", 1), 1),
  ParamType(ArgumentType("5,3,6,2,4,null,null,1", 3), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode230ParamTest, LeetCode230Test, values);

}