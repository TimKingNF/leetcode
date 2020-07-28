//
// Created by timking.nf@foxmail.com on 2020/7/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_02_06.palindrome-linked-list-lcci.h"

namespace LeetCode_02_06 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_02_06Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_02_06Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_02_06::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode, int>(argument);
  ASSERT_EQ(solution->isPalindrome(head), ret);
  link_list_print<ListNode>(head);
}

auto values = ::testing::Values(
  ParamType({1,2,2,1}, true),
  ParamType({1,2}, false),
  ParamType({1,2,1}, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_02_06ParamTest, LeetCode_02_06Test, values);

}