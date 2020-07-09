//
// Created by timking.nf@foxmail.com on 2020/5/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_21.diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.h"

namespace LeetCode_21 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_21Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_21Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_21::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<int> asserted = solution->exchange(argument);
  ASSERT_EQ(asserted, ret);  // 断言结果
}

ArgumentType p1{1,2,3,4};
ResultType r1{1,3,2,4};

ArgumentType p2{2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1};
ResultType r2{1, 5, 3, 5, 13, 1, 11, 1, 11, 11, 18, 8, 12, 16, 16, 2};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_21ParamTest, LeetCode_21Test, values);

}

