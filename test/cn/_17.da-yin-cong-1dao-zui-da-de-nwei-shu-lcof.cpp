//
// Created by timking.nf@foxmail.com on 2020/5/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_17.da-yin-cong-1dao-zui-da-de-nwei-shu-lcof.h"

namespace LeetCode_17 {

typedef int ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_17Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_17Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_17::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->printNumbers(argument), ret);  // 断言结果
}

ResultType r1{1,2,3,4,5,6,7,8,9};

auto values = ::testing::Values(
  ParamType(1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_17ParamTest, LeetCode_17Test, values);

}
