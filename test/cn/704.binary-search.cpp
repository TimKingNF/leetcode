//
// Created by timking.nf@foxmail.com on 2020/7/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "704.binary-search.h"

namespace LeetCode704 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode704Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode704Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode704::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  ASSERT_EQ(solution->search(nums, target), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({-1,0,3,5,9,12}, 9), 4),
  ParamType(ArgumentType({-1,0,3,5,9,12}, 2), -1),
  ParamType(ArgumentType({5}, 5), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode704ParamTest, LeetCode704Test, values);

}