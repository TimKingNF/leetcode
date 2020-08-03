//
// Created by timking.nf@foxmail.com on 2020/8/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "876.middle-of-the-linked-list.h"

namespace LeetCode876 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode876Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode876Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode876::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode>(argument);
  ASSERT_EQ(solution->middleNode(head)->val, ret);
}

auto values = ::testing::Values(
  ParamType({1,2,3,4,5}, 3),
  ParamType({1,2,3,4,5,6}, 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode876ParamTest, LeetCode876Test, values);

}