//
// Created by timking.nf@foxmail.com on 2020/9/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "148.sort-list.h"

namespace LeetCode148 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode148Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode148Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode148::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode *head = construct_link_list<ListNode>(argument);
  ListNode *assertedHead = solution->sortList(head);
  ListNode *retHead = construct_link_list<ListNode>(ret);

  // link_list_print(assertedHead);
  // link_list_print(retHead);
  ASSERT_TRUE(link_list_cmp(assertedHead, retHead));
}

auto values = ::testing::Values(
  // ParamType({4,2,1,3}, {1,2,3,4}),
  ParamType({-1,-2,5,3,4,0}, {-2,-1,0,3,4,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode148ParamTest, LeetCode148Test, values);

}