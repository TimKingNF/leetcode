//
// Created by timking.nf@foxmail.com on 2020/5/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "717.1-bit-and-2-bit-characters.h"

namespace LeetCode717 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode717Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode717Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode717::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isOneBitCharacter(argument), ret);  // 断言结果
}

ArgumentType p1{1,0,0};
ArgumentType p2{1,1,1,0};

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode717ParamTest, LeetCode717Test, values);

}
