//
// Created by timking.nf@foxmail.com on 2020/7/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "95.unique-binary-search-trees-ii.h"

namespace LeetCode95 {

typedef int ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode95Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode95Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode95::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<TreeNode*> trees = solution->generateTrees(argument);
  for (auto root : trees)
    ASSERT_TRUE(ret.count(treeSerialize(root)));
}

auto values = ::testing::Values(
  ParamType(3, {"1,null,3,2",
                "3,2,null,1",
                "3,1,null,null,2",
                "2,1,3",
                "1,null,2,null,3"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode95ParamTest, LeetCode95Test, values);

}