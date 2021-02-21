//
// Created by timking.nf@foxmail.com on 2021/2/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "92.reverse-linked-list-ii.h"

namespace LeetCode92 {

typedef tuple<vector<int>, int, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode92Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode92Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode92::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int m, n;
  tie(args, m, n) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* result = construct_link_list<ListNode>(ret);

  ListNode* asserted = solution->reverseBetween(head, m, n);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(asserted, result));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 2, 4), {1,4,3,2,5}),
  ParamType(ArgumentType({1,2,3,4,5}, 1, 5), {5,4,3,2,1}),
  ParamType(ArgumentType({1,2}, 1, 1), {1,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode92ParamTest, LeetCode92Test, values);

}