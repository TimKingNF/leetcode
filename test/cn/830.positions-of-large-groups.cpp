//
// Created by timking.nf@foxmail.com on 2020/6/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "830.positions-of-large-groups.h"

namespace LeetCode830 {

typedef string ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode830Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode830Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode830::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->largeGroupPositions(argument), ret);  // 断言结果
}

ArgumentType p1 = "abbxxxxzzy";
ResultType r1{{3,6}};

ArgumentType p2 = "abc";
ResultType r2{};

ArgumentType p3 = "abcdddeeeeaabbbcd";
ResultType r3{{3,5},{6,9},{12,14}};

ArgumentType p4 = "a";

ArgumentType p5 = "abccc";
ResultType r5{{2,4}};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3),
  ParamType(p4, r2),
  ParamType(p5, r5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode830ParamTest, LeetCode830Test, values);

}