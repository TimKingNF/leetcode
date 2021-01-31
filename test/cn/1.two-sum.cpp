//
// Created by timking.nf@foxmail.com on 2020/5/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1.two-sum.h"

namespace LeetCode1 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  ASSERT_EQ(solution->twoSum(nums, target), ret);  // 断言结果

}

auto values = ::testing::Values(
  ParamType(ArgumentType({2, 7, 11, 15}, 9), {0, 1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1ParamTest, LeetCode1Test, values);

}
