//
// Created by timking.nf@foxmail.com on 2021/2/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "82.remove-duplicates-from-sorted-list-ii.h"

namespace LeetCode82 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode82Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode82Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode82::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode>(argument);
  ListNode* asserted = solution->deleteDuplicates(head);
  ListNode* retHead = construct_link_list<ListNode>(ret);

  // link_list_print(asserted);
  // link_list_print(retHead);
  ASSERT_TRUE(link_list_cmp(asserted, retHead));
}

auto values = ::testing::Values(
  ParamType({1, 1}, {}),
  ParamType({1, 1, 2}, {2}),
  ParamType({1, 2, 2}, {1}),
  ParamType({1,1,1,2,3}, {2,3}),
  ParamType({1,2,3,3,4,4,5}, {1,2,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode82ParamTest, LeetCode82Test, values);

}