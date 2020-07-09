//
// Created by timking.nf@foxmail.com on 2020/6/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "34.find-first-and-last-position-of-element-in-sorted-array.h"

namespace LeetCode34 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode34Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode34Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode34::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  ASSERT_EQ(solution->searchRange(nums, target), ret);  // 断言结果
}

vector<int> p1_0{5,7,7,8,8,10};
vector<int> p3_0{2,2};
vector<int> p4_0{1,1,2};
ArgumentType p1(p1_0, 8);
ArgumentType p2(p1_0, 6);
ArgumentType p3(p3_0, 3);
ArgumentType p4(p4_0, 1);

ResultType r1{3, 4};
ResultType r2{-1, -1};
ResultType r4{0, 1};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r2),
  ParamType(p4, r4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode34ParamTest, LeetCode34Test, values);

}
