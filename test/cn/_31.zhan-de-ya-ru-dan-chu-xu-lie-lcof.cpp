//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_31.zhan-de-ya-ru-dan-chu-xu-lie-lcof.h"

namespace LeetCode_31 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_31Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_31Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_31::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<int> pushed, popped;
  tie(pushed, popped) = arguments;

  ASSERT_EQ(solution->validateStackSequences(pushed, popped), ret);  // 断言结果
}

vector<int> p1_0{1,2,3,4,5};
vector<int> p1_1{4,5,3,2,1};
ArgumentType p1(p1_0, p1_1);

vector<int> p2_1{4,3,5,1,2};
ArgumentType p2(p1_0, p2_1);

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_31ParamTest, LeetCode_31Test, values);

}