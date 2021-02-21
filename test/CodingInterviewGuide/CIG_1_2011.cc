//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2011.hpp"

namespace CIG_1_2011 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_2011_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2011_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2011::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int m;
  tie(args, m) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* result = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->listPartition(head, m);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(result, asserted));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({9,0,4,5,1}, 3), {0,1,9,4,5}),
  ParamType(ArgumentType({9,0,3,4,5,1}, 3), {0,1,3,9,4,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2011_ParamTest, CIG_1_2011_Test, values);

}