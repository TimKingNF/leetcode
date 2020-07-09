//
// Created by timking.nf@foxmail.com on 2020/5/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "414.third-maximum-number.h"

namespace LeetCode414 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode414Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode414Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode414::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->thirdMax(argument), ret);  // 断言结果
}

ArgumentType p1{3,2,1};
ArgumentType p2{1,2};
ArgumentType p3{2,2,3,1};
ArgumentType p4{1,2,-2147483648};

auto values = ::testing::Values(
  ParamType(p1, 1),
  ParamType(p2, 2),
  ParamType(p3, 1),
  ParamType(p4, -2147483648)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode414ParamTest, LeetCode414Test, values);

}
