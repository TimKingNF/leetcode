//
// Created by timking.nf@foxmail.com on 2021/3/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "354.russian-doll-envelopes.h"

namespace LeetCode354 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode354Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode354Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode354::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maxEnvelopes(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{5,4},{6,4},{6,7},{2,3}}, 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode354ParamTest, LeetCode354Test, values);

}