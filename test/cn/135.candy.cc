//
// Created by timking.nf@foxmail.com on 2020/12/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "135.candy.h"

namespace LeetCode135 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode135Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode135Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode135::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->candy(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,0,2}, 5),
  ParamType({1,2,2}, 4),
  ParamType({1,0,2,3,0,1}, 11),
  ParamType({}, 0),
  ParamType({0}, 1),
  ParamType({1,0}, 3),
  ParamType({1,3,2,2,1}, 7),
  ParamType({1,6,10,8,7,3,2}, 18)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode135ParamTest, LeetCode135Test, values);

}