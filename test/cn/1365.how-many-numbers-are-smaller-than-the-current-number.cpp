//
// Created by timking.nf@foxmail.com on 2020/10/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1365.how-many-numbers-are-smaller-than-the-current-number.h"

namespace LeetCode1365 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1365Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1365Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1365::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->smallerNumbersThanCurrent(argument), ret);
}

auto values = ::testing::Values(
  ParamType({8,1,2,2,3}, {4,0,1,1,3}),
  ParamType({6,5,4,8}, {2,1,0,3}),
  ParamType({7,7,7,7}, {0,0,0,0})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1365ParamTest, LeetCode1365Test, values);

}