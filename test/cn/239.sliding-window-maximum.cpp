//
// Created by timking.nf@foxmail.com on 2020/6/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "239.sliding-window-maximum.h"

namespace LeetCode239 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode239Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode239Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode239::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<int> nums;
  int k;
  tie(nums, k) = arguments;

  ASSERT_EQ(solution->maxSlidingWindow(nums, k), ret);
}

vector<int> p1_0{1,3,-1,-3,5,3,6,7};
ArgumentType p1(p1_0, 3);
ResultType r1{3,3,5,5,6,7};

vector<int> p2_0{9,10,9,-7,-4,-8,2,-6};
ArgumentType p2(p2_0, 5);
ResultType r2{10,10,9,2};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode239ParamTest, LeetCode239Test, values);

}
