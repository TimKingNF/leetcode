//
// Created by timking.nf@foxmail.com on 2020/7/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "19.remove-nth-node-from-end-of-list.h"

namespace LeetCode19 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode19Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode19Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode19::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> inputs;
  int n;
  tie(inputs, n) = arguments;
  ListNode* head = construct_link_list<ListNode, int>(inputs);
  head = solution->removeNthFromEnd(head, n);

  ListNode* ret_link_list = construct_link_list<ListNode, int>(ret);
  ASSERT_TRUE(link_list_cmp(head, ret_link_list));  // 因为值都是唯一，只比较值是否一样即可
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 2), {1,2,3,5}),
  ParamType(ArgumentType({1,2,3,4,5}, 1), {1,2,3,4}),
  ParamType(ArgumentType({1,2,3,4,5}, 5), {2,3,4,5}),
  ParamType(ArgumentType({1}, 1), {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode19ParamTest, LeetCode19Test, values);

}