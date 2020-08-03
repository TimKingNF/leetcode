//
// Created by timking.nf@foxmail.com on 2020/7/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "744.find-smallest-letter-greater-than-target.h"

namespace LeetCode744 {

typedef tuple<vector<char>, char> ArgumentType;
typedef char ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode744Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode744Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode744::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<char> letters;
  char target;
  tie(letters, target) = arguments;

  ASSERT_EQ(solution->nextGreatestLetter(letters, target), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({'c', 'f', 'j'}, 'a'), 'c'),
  ParamType(ArgumentType({'c', 'f', 'j'}, 'c'), 'f'),
  ParamType(ArgumentType({'c', 'f', 'j'}, 'd'), 'f'),
  ParamType(ArgumentType({'c', 'f', 'j'}, 'g'), 'j'),
  ParamType(ArgumentType({'c', 'f', 'j'}, 'j'), 'c')
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode744ParamTest, LeetCode744Test, values);

}