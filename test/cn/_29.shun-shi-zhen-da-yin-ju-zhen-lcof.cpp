//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_29.shun-shi-zhen-da-yin-ju-zhen-lcof.h"

namespace LeetCode_29 {

typedef vector<vector<int>> MatrixType;
typedef MatrixType ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_29Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_29Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_29::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->spiralOrder(argument), ret);  // 断言结果
}

ArgumentType p1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
vector<int> r1{1,2,3,6,9,8,7,4,5};

ArgumentType p2{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
vector<int> r2{1,2,3,4,8,12,11,10,9,5,6,7};

ArgumentType p3{{7}, {8}, {9}};
vector<int> r3{7, 8, 9};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_29ParamTest, LeetCode_29Test, values);

}