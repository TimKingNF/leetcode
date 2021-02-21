//
// Created by timking.nf@foxmail.com on 2021/2/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1423.maximum-points-you-can-obtain-from-cards.h"

namespace LeetCode1423 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1423Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1423Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1423::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> cardPoints;
  int k;
  tie(cardPoints, k) = arguments;

  ASSERT_EQ(solution->maxScore(cardPoints, k), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5,6,1}, 3), 12),
  ParamType(ArgumentType({2,2,2}, 2), 4),
  ParamType(ArgumentType({9,7,7,9,7,7,9}, 7), 55),
  ParamType(ArgumentType({1,1000,1}, 1), 1),
  ParamType(ArgumentType({1,79,80,1,1,1,200,1}, 3), 202)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1423ParamTest, LeetCode1423Test, values);

}