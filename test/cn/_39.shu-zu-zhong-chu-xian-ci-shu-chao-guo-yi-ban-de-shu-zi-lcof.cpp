//
// Created by timking.nf@foxmail.com on 2020/6/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_39.shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof.h"

namespace LeetCode_39 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_39Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_39Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_39::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->majorityElement(argument), ret);  // 断言结果
}

ArgumentType p1{3,2,3};
ArgumentType p2{2,2,1,1,1,2,2};

ResultType r1 = 3;
ResultType r2 = 2;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_39ParamTest, LeetCode_39Test, values);

}
