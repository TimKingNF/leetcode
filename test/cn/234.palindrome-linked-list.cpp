//
// Created by timking.nf@foxmail.com on 2020/7/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "234.palindrome-linked-list.h"

namespace LeetCode234 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode234Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode234Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode234::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode, int>(argument);
  ASSERT_EQ(solution->isPalindrome(head), ret);
  // link_list_print<ListNode>(head);
}

auto values = ::testing::Values(
  ParamType({1,2,2,1}, true),
  ParamType({1,2}, false),
  ParamType({1,2,1}, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode234ParamTest, LeetCode234Test, values);

}