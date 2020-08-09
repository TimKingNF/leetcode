//
// Created by timking.nf@foxmail.com on 2020/8/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "220.contains-duplicate-iii.h"

namespace LeetCode220 {

typedef tuple<vector<int>, int, int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode220Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode220Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode220::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int k, t;
  tie(nums, k, t) = arguments;
  ASSERT_EQ(solution->containsNearbyAlmostDuplicate(nums, k, t), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,1}, 3, 0), true),
  ParamType(ArgumentType({1,0,1,1}, 1, 2), true),
  ParamType(ArgumentType({1,5,9,1,5,9}, 2, 3), false),
  ParamType(ArgumentType({10, 15, 18, 24}, 3, 3), true),
  ParamType(ArgumentType({-1, 2147483647}, 1, 2147483647), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode220ParamTest, LeetCode220Test, values);

}