//
// Created by timking.nf@foxmail.com on 2020/5/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "665.non-decreasing-array.h"

namespace LeetCode665 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode665Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode665Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode665::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->checkPossibility(argument), ret);  // 断言结果
}

ArgumentType p1{4,2,3};
ArgumentType p2{4,2,1};
ArgumentType p3{3,4,2,3};

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false),
  ParamType(p3, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode665ParamTest, LeetCode665Test, values);

}
