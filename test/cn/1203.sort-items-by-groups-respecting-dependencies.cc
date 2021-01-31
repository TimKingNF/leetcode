//
// Created by timking.nf@foxmail.com on 2021/1/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1203.sort-items-by-groups-respecting-dependencies.h"

namespace LeetCode1203 {

typedef tuple<int, int, vector<int>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1203Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1203Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1203::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int n, m;
  vector<int> group;
  vector<vector<int>> beforeItems;
  tie(n, m, group, beforeItems) = arguments;

  ASSERT_EQ(solution->sortItems(n, m, group, beforeItems), ret);
}

auto values = ::testing::Values(
  // ParamType(ArgumentType(8, 2, {-1,-1,1,0,0,1,0,-1}, {{},{6},{5},{6},{3,6},{},{},{}}),
  //           {6,3,4,1,5,2,0,7}),
  ParamType(ArgumentType(8,2, {-1,-1,1,0,0,1,0,-1}, {{},{6},{5},{6},{3},{},{4},{}}),
            {}),
  ParamType(ArgumentType(5, 3, {0,0,2,1,0}, {{3},{},{},{},{1,3,2}}),
            {3,2,0,1,4})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1203ParamTest, LeetCode1203Test, values);

}