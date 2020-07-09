//
// Created by timking.nf@foxmail.com on 2020/7/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1290.convert-binary-number-in-a-linked-list-to-integer.h"

namespace LeetCode1290 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1290Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1290Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1290::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode, int>(argument);
  ASSERT_EQ(solution->getDecimalValue(head), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,0,1}, 5),
  ParamType({0}, 0),
  ParamType({1}, 1),
  ParamType({1,0,0,1,0,0,1,1,1,0,0,0,0,0,0}, 18880),
  ParamType({0, 0}, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1290ParamTest, LeetCode1290Test, values);

}