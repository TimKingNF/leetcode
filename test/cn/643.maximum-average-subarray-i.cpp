//
// Created by timking.nf@foxmail.com on 2020/5/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "643.maximum-average-subarray-i.h"

namespace LeetCode643 {

typedef tuple<vector<int>, int> ArgumentType;
typedef double ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode643Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode643Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode643::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int n;
  tie(nums, n) = arguments;

  ASSERT_EQ(solution->findMaxAverage(nums, n), ret);  // 断言结果
}

vector<int> p1_0{1,12,-5,-6,50,3};
ArgumentType p1(p1_0, 4);

vector<int> p2_0{-1};
ArgumentType p2(p2_0, 1);

auto values = ::testing::Values(
  ParamType(p1, 12.75),
  ParamType(p2, -1.0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode643ParamTest, LeetCode643Test, values);

}
