//
// Created by timking.nf@foxmail.com on 2020/6/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_34.er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof.h"

namespace LeetCode_34 {

typedef tuple<string, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_34Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_34Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_34::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int sum;
  tie(args, sum) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode>(args);
  ASSERT_EQ(solution->pathSum(root, sum), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("5,4,8,11,null,13,4,7,2,null,null,5,1", 22),
            {{5, 4, 11, 2}, {5, 8, 4, 5}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_34ParamTest, LeetCode_34Test, values);

}