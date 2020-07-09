//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_30.bao-han-minhan-shu-de-zhan-lcof.h"

namespace LeetCode_30 {

typedef vector<int> ArgumentType;
typedef tuple<vector<int>, vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_30Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_30Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();
  vector<int> topArray;
  vector<int> minArray;
  tie(topArray, minArray) = ret;

  auto minStack = new MinStack();

  for (auto v : argument) {
    minStack->push(v);
  }
  // pop
  for (int i = argument.size()-1; i >=0 ; --i) {
    ASSERT_EQ(minStack->top(), topArray[i]);
    ASSERT_EQ(minStack->min(), minArray[i]);
    minStack->pop();
  }
}

ArgumentType p1{-2, 0, -3};
vector<int> r1_0{-2, 0, -3};  // 每次pop之后的栈顶元素
vector<int> r1_1{-2, -2, -3};  // 每次pop之后调用min获取到的最小值
ResultType r1(r1_0, r1_1);

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_30ParamTest, LeetCode_30Test, values);

}