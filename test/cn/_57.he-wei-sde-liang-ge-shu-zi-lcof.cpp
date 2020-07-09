//
// Created by timking.nf@foxmail.com on 2020/6/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_57.he-wei-sde-liang-ge-shu-zi-lcof.h"

namespace LeetCode_57 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_57Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_57Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_57::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  vector<int> asserted = solution->twoSum(nums, target);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

vector<int> p1_0{2,7,11,15};
ArgumentType p1(p1_0, 9);
ResultType r1{2,7};

vector<int> p2_0{10,26,30,31,47,60};
ArgumentType p2(p2_0, 40);
ResultType r2{10, 30};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_57ParamTest, LeetCode_57Test, values);

}