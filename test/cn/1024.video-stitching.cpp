//
// Created by timking.nf@foxmail.com on 2020/10/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1024.video-stitching.h"

namespace LeetCode1024 {

typedef tuple<vector<vector<int>>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1024Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1024Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1024::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<int>> clips;
  int T;
  tie(clips, T) = arguments;

  ASSERT_EQ(solution->videoStitching(clips, T), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}}, 10), 3),
  ParamType(ArgumentType({{0,1},{1,2}}, 5), -1),
  ParamType(ArgumentType({{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},
                          {4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}}, 9), 3),
  ParamType(ArgumentType({{0,4}, {2,8}}, 5), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1024ParamTest, LeetCode1024Test, values);

}