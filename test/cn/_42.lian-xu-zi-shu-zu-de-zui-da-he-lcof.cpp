//
// Created by timking.nf@foxmail.com on 2020/6/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_42.lian-xu-zi-shu-zu-de-zui-da-he-lcof.h"

namespace LeetCode_42 {

typedef vector<int> ArgumentType;
typedef tuple<ArgumentType, int> ParamType;

class LeetCode_42Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_42Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_42::Solution();
  ArgumentType arguments;
  int ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->maxSubArray(arguments), ret);  // 断言结果
}

ArgumentType p1{-2,1,-3,4,-1,2,1,-5,4};

auto values = ::testing::Values(
  ParamType(p1, 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_42ParamTest, LeetCode_42Test, values);

}