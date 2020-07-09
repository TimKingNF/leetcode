//
// Created by timking.nf@foxmail.com on 2020/5/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "153.find-minimum-in-rotated-sorted-array.h"

namespace LeetCode153 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode153Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode153Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode153::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findMin(argument), ret);  // 断言结果
}

ArgumentType p1{3,4,5,1,2};
ArgumentType p2{4,5,6,7,0,1,2};
ArgumentType p3{1};

auto values = ::testing::Values(
  ParamType(p1, 1),
  ParamType(p2, 0),
  ParamType(p3, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode153ParamTest, LeetCode153Test, values);

}
