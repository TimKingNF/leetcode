//
// Created by timking.nf@foxmail.com on 2020/7/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "24.swap-nodes-in-pairs.h"

namespace LeetCode24 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode24Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode24Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode24::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode>(argument);
  ListNode* retHead = construct_link_list<ListNode>(ret);
  ASSERT_TRUE(link_list_cmp(solution->swapPairs(head), retHead));  // 断言结果
}

auto values = ::testing::Values(
  ParamType({}, {}),
  ParamType({1,2,3,4}, {2,1,4,3}),
  ParamType({1,2,3}, {2,1,3})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode24ParamTest, LeetCode24Test, values);

}
