//
// Created by timking.nf@foxmail.com on 2020/6/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_45.ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof.h"

namespace LeetCode_45 {

typedef vector<int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_45Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_45Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_45::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->minNumber(arguments), ret);  // 断言结果
}

ArgumentType p1{10, 2};
ArgumentType p2{3,30,34,5,9};

auto values = ::testing::Values(
  ParamType(p1, "102"),
  ParamType(p2, "3033459")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_45ParamTest, LeetCode_45Test, values);

}