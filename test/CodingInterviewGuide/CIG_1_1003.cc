//
// Created by timking.nf@foxmail.com on 2021/1/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_1003.hpp"

namespace CIG_1_1003 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

vector<int> getStackFromTopToBottom(stack<int> stk) {
  vector<int> ans;
  while (!stk.empty()) {
    ans.push_back(stk.top());
    stk.pop();
  }
  return ans;
}

stack<int> constructStack(vector<int>& nums) {
  stack<int> stk;
  for (int num : nums) stk.push(num);
  return stk;
}

class CIG_1_1003_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_1003_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_1003::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  stack<int> stk = constructStack(argument);
  solution->reverse(stk);
  ASSERT_EQ(getStackFromTopToBottom(stk), ret);
}

auto values = ::testing::Values(
  ParamType({1,2,3,4,5}, {1,2,3,4,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_1003_ParamTest, CIG_1_1003_Test, values);

}