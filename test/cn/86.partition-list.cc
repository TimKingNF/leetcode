//
// Created by timking.nf@foxmail.com on 2021/1/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "86.partition-list.h"

namespace LeetCode86 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode86Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode86Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode86::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int x;
  tie(args, x) = arguments;
  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* retHead = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->partition(head, x);

  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(asserted, retHead));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,4,3,2,5,2}, 3), {1,2,2,4,3,5}),
  ParamType(ArgumentType({1,4,3,2,5,2}, 10), {1,4,3,2,5,2}),
  ParamType(ArgumentType({1,4,3,2,5,2}, 0), {1,4,3,2,5,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode86ParamTest, LeetCode86Test, values);

}