//
// Created by timking.nf@foxmail.com on 2020/8/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "215.kth-largest-element-in-an-array.h"

namespace LeetCode215 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode215Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode215Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode215::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int k;
  tie(nums, k) = arguments;

  ASSERT_EQ(solution->findKthLargest(nums, k), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({3,2,1,5,6,4}, 2), 5),
  ParamType(ArgumentType({3,2,3,1,2,4,5,5,6}, 4), 4),
  ParamType(ArgumentType({3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6}, 20), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode215ParamTest, LeetCode215Test, values);

}