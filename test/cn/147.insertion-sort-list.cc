//
// Created by timking.nf@foxmail.com on 2020/11/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "147.insertion-sort-list.h"

namespace LeetCode147 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode147Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode147Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode147::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode>(argument);
  ListNode* asserted = solution->insertionSortList(head);
  ListNode* result = construct_link_list<ListNode>(ret);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(asserted, result));
}

auto values = ::testing::Values(
  ParamType({4,2,1,3}, {1,2,3,4}),
  ParamType({-1,5,3,4,0}, {-1,0,3,4,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode147ParamTest, LeetCode147Test, values);

}