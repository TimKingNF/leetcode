//
// Created by timking.nf@foxmail.com on 2020/7/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "33.search-in-rotated-sorted-array.h"

namespace LeetCode33 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode33Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode33Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode33::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  ASSERT_EQ(solution->search(nums, target), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({4,5,6,7,0,1,2}, 0), 4),
  ParamType(ArgumentType({4,5,6,7,0,1,2}, 3), -1),
  ParamType(ArgumentType({5}, 5), 0),
  ParamType(ArgumentType({1}, 1), 0),
  ParamType(ArgumentType({1,2,3,4,5,6}, 5), 4),
  ParamType(ArgumentType({5,1,3}, 5), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode33ParamTest, LeetCode33Test, values);

}