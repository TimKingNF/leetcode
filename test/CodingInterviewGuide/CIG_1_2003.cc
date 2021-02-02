//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2003.hpp"

namespace CIG_1_2003 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

void print_double_link_list(ListNode* head) {
  if (!head) return;
  while (head) {
    cout << "<" << (head->prev ? to_string(head->prev->val) : "") << ",";
    cout << head->val << ",";
    cout << (head->next ? to_string(head->next->val) : "") << ">,";
    head = head->next;
  }
  cout << endl;
}

class CIG_1_2003_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2003_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2003::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> inputs;
  int n;
  tie(inputs, n) = arguments;
  ListNode* head = construct_double_link_list<ListNode, int>(inputs);
  // print_double_link_list(head);
  head = solution->removeNthFromEnd(head, n);

  ListNode* ret_link_list = construct_double_link_list<ListNode, int>(ret);
  // print_double_link_list(ret_link_list);
  ASSERT_TRUE(link_list_cmp(head, ret_link_list));  // 因为值都是唯一，只比较值是否一样即可
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 2), {1,2,3,5}),
  ParamType(ArgumentType({1,2,3,4,5}, 1), {1,2,3,4}),
  ParamType(ArgumentType({1,2,3,4,5}, 5), {2,3,4,5}),
  ParamType(ArgumentType({1}, 1), {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2003_ParamTest, CIG_1_2003_Test, values);

}