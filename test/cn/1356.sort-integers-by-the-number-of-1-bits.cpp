//
// Created by timking.nf@foxmail.com on 2020/7/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1356.sort-integers-by-the-number-of-1-bits.h"

namespace LeetCode1356 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1356Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1356Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1356::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->sortByBits(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({0,1,2,3,4,5,6,7,8}, {0,1,2,4,8,3,5,6,7}),
  ParamType({1024,512,256,128,64,32,16,8,4,2,1}, {1,2,4,8,16,32,64,128,256,512,1024}),
  ParamType({10000,10000}, {10000,10000}),
  ParamType({2,3,5,7,11,13,17,19}, {2,3,5,17,7,11,13,19}),
  ParamType({10,100,1000,10000}, {10,100,10000,1000})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1356ParamTest, LeetCode1356Test, values);

}