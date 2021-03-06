//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2023.hpp"

namespace CIG_1_2023 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_2023_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2023_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2023::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode>(argument);
  ListNode* result = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->relocate(head);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(result, asserted));
}

auto values = ::testing::Values(
  ParamType({1}, {1}),
  ParamType({1,2}, {1,2}),
  ParamType({1,2,3}, {1,2,3}),
  ParamType({1,2,3,4}, {1,3,2,4}),
  ParamType({1,2,3,4,5}, {1,3,2,4,5}),
  ParamType({1,2,3,4,5,6}, {1,4,2,5,3,6})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2023_ParamTest, CIG_1_2023_Test, values);

}