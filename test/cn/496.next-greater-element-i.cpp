//
// Created by timking.nf@foxmail.com on 2020/6/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "496.next-greater-element-i.h"

namespace LeetCode496 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode496Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode496Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode496::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums1, nums2;
  tie(nums1, nums2) = arguments;

  ASSERT_EQ(solution->nextGreaterElement(nums1, nums2), ret);  // 断言结果
}

vector<int> p1_0{4,1,2};
vector<int> p1_1{1,3,4,2};
ArgumentType p1(p1_0, p1_1);
ResultType r1{-1,3,-1};

vector<int> p2_0{2,4};
vector<int> p2_1{1,2,3,4};
ArgumentType p2(p2_0, p2_1);
ResultType r2{3,-1};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode496ParamTest, LeetCode496Test, values);

}