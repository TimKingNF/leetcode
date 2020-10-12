//
// Created by timking.nf@foxmail.com on 2020/9/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "621.task-scheduler.h"

namespace LeetCode621 {

typedef tuple<vector<char>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode621Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode621Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode621::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<char> tasks;
  int n;
  tie(tasks, n) = arguments;
  ASSERT_EQ(solution->leastInterval(tasks, n), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({'A', 'A', 'A', 'B', 'B', 'B'}, 2), 8)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode621ParamTest, LeetCode621Test, values);

}