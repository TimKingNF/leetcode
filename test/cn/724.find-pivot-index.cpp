//
// Created by timking.nf@foxmail.com on 2020/5/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "724.find-pivot-index.h"

namespace LeetCode724 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode724Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode724Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode724::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->pivotIndex(argument), ret);  // 断言结果
}

ArgumentType p1{1, 7, 3, 6, 5, 6};
ArgumentType p2{1,2,3};
ArgumentType p3{-1,-1,-1,-1,-1,-1};
ArgumentType p4{-1,-1,-1,-1,-1,0};
ArgumentType p5{0,1};
ArgumentType p6{1};

auto values = ::testing::Values(
  ParamType(p1, 3),
  ParamType(p2, -1),
  ParamType(p3, -1),
  ParamType(p4, 2),
  ParamType(p5, 1),
  ParamType(p6, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode724ParamTest, LeetCode724Test, values);

}
