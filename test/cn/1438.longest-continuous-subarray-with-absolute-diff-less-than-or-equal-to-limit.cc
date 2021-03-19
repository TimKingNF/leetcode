//
// Created by timking.nf@foxmail.com on 2021/2/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1438.longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit.h"

namespace LeetCode1438 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1438Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1438Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1438::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int limit;
  tie(nums, limit) = arguments;

  ASSERT_EQ(solution->longestSubarray(nums, limit), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({8,2,4,7}, 4), 2),
  ParamType(ArgumentType({10,1,2,4,7,2}, 5), 4),
  ParamType(ArgumentType({4,2,2,2,4,4,2,2}, 0), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1438ParamTest, LeetCode1438Test, values);

}