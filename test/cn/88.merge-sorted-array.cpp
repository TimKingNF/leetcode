//
// Created by timking.nf@foxmail.com on 2020/5/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "88.merge-sorted-array.h"

namespace LeetCode88 {

typedef tuple<vector<int>, int, vector<int>, int>  ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode88Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode88Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode88::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums1, nums2;
  int m, n;
  tie(nums1, m, nums2, n) = arguments;

  solution->merge(nums1, m, nums2, n);
  ASSERT_EQ(nums1, ret);  // 断言结果
}

vector<int> p1_0{1,2,3,0,0,0};
vector<int> p1_2{2,5,6};
ArgumentType p1(p1_0, 3, p1_2, 3);

ResultType r1{1,2,2,3,5,6};

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode88ParamTest, LeetCode88Test, values);

}