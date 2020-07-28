//
// Created by timking.nf@foxmail.com on 610610/7/618.
//

#include "gtest/gtest.h"
#include "header.h"
#include "61.rotate-list.h"

namespace LeetCode61 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode61Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode61Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode61::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int k;
  tie(args, k) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* assertedHead = solution->rotateRight(head, k);
  ListNode* resultHead = construct_link_list<ListNode>(ret);
  ASSERT_TRUE(link_list_cmp(assertedHead, resultHead));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 2), {4,5,1,2,3}),
  ParamType(ArgumentType({0,1,2}, 4), {2,0,1}),
  ParamType(ArgumentType({0,1,2}, 9), {0,1,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode61ParamTest, LeetCode61Test, values);

}