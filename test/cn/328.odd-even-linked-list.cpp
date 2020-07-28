//
// Created by timking.nf@foxmail.com on 2020/7/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "328.odd-even-linked-list.h"

namespace LeetCode328 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode328Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode328Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode328::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode, int>(argument);
  ListNode* asserted = solution->oddEvenList(head);
  ListNode* resultHead = construct_link_list<ListNode, int>(ret);

  ASSERT_TRUE(link_list_cmp(asserted, resultHead));  // 断言结果

}

auto values = ::testing::Values(
  ParamType({1}, {1}),
  ParamType({1,2}, {1,2}),
  ParamType({1,2,3,4,5}, {1,3,5,2,4}),
  ParamType({2,1,3,5,6,4,7}, {2,3,6,7,1,5,4})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode328ParamTest, LeetCode328Test, values);

}