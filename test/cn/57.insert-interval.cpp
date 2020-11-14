//
// Created by timking.nf@foxmail.com on 2020/11/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "57.insert-interval.h"

namespace LeetCode57 {

typedef tuple<vector<vector<int>>, vector<int>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode57Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode57Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode57::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<int>> intervals;
  vector<int> newInterval;
  tie(intervals, newInterval) = arguments;

  ASSERT_EQ(solution->insert(intervals, newInterval), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({}, {6,9}),
            {{6,9}}),
  ParamType(ArgumentType({{1,3}}, {6,9}),
            {{1,3}, {6,9}}),
  ParamType(ArgumentType({{1,3}, {6,9}}, {-1,0}),
            {{-1,0}, {1,3}, {6,9}}),
  ParamType(ArgumentType({{1,3}, {6,9}}, {4,5}),
            {{1,3}, {4,5}, {6,9}}),
  ParamType(ArgumentType({{1,3}, {6,9}}, {2,5}), {{1,5}, {6,9}}),
  ParamType(ArgumentType({{1,2}, {3,5}, {6,7}, {8,10}, {12,16}, {17,18}}, {4,8}),
            {{1,2}, {3,10}, {12,16}, {17,18}}),
  ParamType(ArgumentType({{1,2}, {3,5}, {6,7}, {8,10}}, {4,8}),
            {{1,2}, {3,10}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode57ParamTest, LeetCode57Test, values);

}