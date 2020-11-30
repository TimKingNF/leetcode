//
// Created by timking.nf@foxmail.com on 2020/11/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "406.queue-reconstruction-by-height.h"

namespace LeetCode406 {

typedef vector<vector<int>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode406Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode406Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode406::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reconstructQueue(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}},
            {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode406ParamTest, LeetCode406Test, values);

}