//
// Created by timking.nf@foxmail.com on 2020/6/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "56.merge-intervals.h"

namespace LeetCode56 {

typedef vector<vector<int>> ArgumentType;
typedef ArgumentType ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode56Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode56Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode56::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->merge(argument), ret);  // 断言结果
}

ArgumentType p1{{1,3},{2,6},{8,10},{15,18}};
ResultType r1{{1,6},{8,10},{15,18}};

ArgumentType p2{{1,4},{4,5}};
ResultType r2{{1,5}};

ArgumentType p3{{1,4},{0,4}};
ResultType r3{{0,4}};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode56ParamTest, LeetCode56Test, values);

}