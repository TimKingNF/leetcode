//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2017.hpp"

namespace CIG_1_2017 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_2017_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2017_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2017::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int val;
  tie(args, val) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* result = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->removeValueNode(head, val);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(result, asserted));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,3,4}, 3), {1,2,4})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2017_ParamTest, CIG_1_2017_Test, values);

}