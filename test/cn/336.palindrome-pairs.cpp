//
// Created by timking.nf@foxmail.com on 2020/8/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "336.palindrome-pairs.h"

namespace LeetCode336 {

typedef vector<string> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode336Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode336Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode336::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType asserted = solution->palindromePairs(argument);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));  // 断言结果
}

auto values = ::testing::Values(
  ParamType({"abcd","dcba","lls","s","sssll"}, {{0,1},
                                                {1,0},
                                                {2,4},
                                                {3,2}}),
  ParamType({"bat","tab","cat"}, {{0,1},
                                  {1,0}}),
  ParamType({"a", ""}, {{0, 1},
                        {1, 0}}),
  ParamType({"a","abc","aba",""}, {{0,3},
                                   {2,3},
                                   {3,0},
                                   {3,2}}),
  ParamType({"a","b","c","ab","ac","aa"}, {{3,0},
                                           {1,3},
                                           {4,0},
                                           {2,4},
                                           {5,0},
                                           {0,5}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode336ParamTest, LeetCode336Test, values);

}
