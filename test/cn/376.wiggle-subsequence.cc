//
// Created by timking.nf@foxmail.com on 2020/12/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "376.wiggle-subsequence.h"

namespace LeetCode376 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode376Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode376Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode376::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->wiggleMaxLength(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,7,4,9,2,5}, 6),
  ParamType({1,17,5,10,13,15,10,5,16,8}, 7),
  ParamType({1,2,3,4,5,6,7,8,9}, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode376ParamTest, LeetCode376Test, values);

}