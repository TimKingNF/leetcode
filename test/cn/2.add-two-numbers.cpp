//
// Created by timking.nf@foxmail.com on 2020/7/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "2.add-two-numbers.h"

namespace LeetCode2 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode2Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode2Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode2::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> l1_value, l2_value;
  tie(l1_value, l2_value) = arguments;

  ListNode* l1 = construct_link_list<ListNode, int>(l1_value);
  ListNode* l2 = construct_link_list<ListNode, int>(l2_value);
  ListNode* asserted = solution->addTwoNumbers(l1, l2);
  ListNode* resultHead = construct_link_list<ListNode, int>(ret);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(asserted, resultHead));  // 断言结果

}

auto values = ::testing::Values(
  ParamType(ArgumentType({2,4,3}, {5,6,4}), {7,0,8}),
  ParamType(ArgumentType({5}, {5}), {0, 1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode2ParamTest, LeetCode2Test, values);

}