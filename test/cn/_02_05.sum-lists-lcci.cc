//
// Created by timking.nf@foxmail.com on 2020/11/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_02_05.sum-lists-lcci.h"

namespace LeetCode_02_05 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_02_05Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_02_05Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_02_05::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> v1, v2;
  tie(v1, v2) = arguments;
  ListNode *l1 = construct_link_list<ListNode>(v1);
  ListNode *l2 = construct_link_list<ListNode>(v2);
  ListNode *asserted = solution->addTwoNumbers(l1, l2);
  ListNode *ret_head = construct_link_list<ListNode>(ret);

  ASSERT_TRUE(link_list_cmp(asserted, ret_head));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({7,1,6}, {5,9,2}), {2,1,9}),
  ParamType(ArgumentType({0,9,0,1}, {2,1}), {2,0,1,1}),
  ParamType(ArgumentType({5}, {5}), {0, 1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_02_05ParamTest, LeetCode_02_05Test, values);

}