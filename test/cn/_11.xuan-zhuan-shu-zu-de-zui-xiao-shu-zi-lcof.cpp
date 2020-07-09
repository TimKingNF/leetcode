//
// Created by timking.nf@foxmail.com on 2020/5/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_11.xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.h"

namespace LeetCode_11 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_11Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_11Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_11::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->minArray(argument), ret);  // 断言结果
}

ArgumentType p1{3,4,5,1,2};
ArgumentType p2{4,5,6,7,0,1,2};
ArgumentType p3{1};
ArgumentType p4{2,2,2,0,1};
ArgumentType p5{2,0,1,1,1};

auto values = ::testing::Values(
  ParamType(p1, 1),
  ParamType(p2, 0),
  ParamType(p3, 1),
  ParamType(p4, 0),
  ParamType(p5, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_11ParamTest, LeetCode_11Test, values);

}

