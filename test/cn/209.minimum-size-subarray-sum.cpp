//
// Created by timking.nf@foxmail.com on 2020/7/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "209.minimum-size-subarray-sum.h"

namespace LeetCode209 {

typedef tuple<int, vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode209Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode209Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode209::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int s;
  vector<int> nums;
  tie(s, nums) = arguments;

  ASSERT_EQ(solution->minSubArrayLen(s, nums), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(7, {2,3,1,2,4,3}), 2),
  ParamType(ArgumentType(4, {1,4,4}), 1),
  ParamType(ArgumentType(4, {1,1,1}), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode209ParamTest, LeetCode209Test, values);

}