//
// Created by timking.nf@foxmail.com on 2020/5/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "532.k-diff-pairs-in-an-array.h"

namespace LeetCode532 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode532Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode532Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode532::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int k;
  tie(nums, k) = arguments;

  ASSERT_EQ(solution->findPairs(nums, k), ret);  // 断言结果
}

vector<int> p1_0{3, 1, 4, 1, 5};
ArgumentType p1(p1_0, 2);

vector<int> p2_0{1, 2, 3, 4, 5};
ArgumentType p2(p2_0, 1);

vector<int> p3_0{1, 3, 1, 5, 4};
ArgumentType p3(p3_0, 0);

vector<int> p4_0{1,1,1,1,1};
ArgumentType p4(p4_0, 0);

auto values = ::testing::Values(
  ParamType(p1, 2),
  ParamType(p2, 4),
  ParamType(p3, 1),
  ParamType(p4, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode532ParamTest, LeetCode532Test, values);

}
