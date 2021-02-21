//
// Created by timking.nf@foxmail.com on 2021/2/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "25.reverse-nodes-in-k-group.h"

namespace LeetCode25 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode25Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode25Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode25::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int k;
  tie(args, k) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* retHead = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->reverseKGroup(head, k);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(asserted, retHead));  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({}, 10), {}),
  ParamType(ArgumentType({1,2,3,4,5}, 2), {2,1,4,3,5}),
  ParamType(ArgumentType({1,2,3,4,5}, 3), {3,2,1,4,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode25ParamTest, LeetCode25Test, values);

}