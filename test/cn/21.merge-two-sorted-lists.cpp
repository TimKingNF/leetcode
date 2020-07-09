//
// Created by timking.nf@foxmail.com on 2020/5/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "21.merge-two-sorted-lists.h"

namespace LeetCode21 {

typedef tuple<ListNode*, ListNode*> ArgumentType;
typedef ListNode* ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode21Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode21Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode21::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ListNode *first, *second;
  tie(first, second) = arguments;

  ASSERT_TRUE(link_list_cmp(solution->mergeTwoLists(first, second), ret));  // 断言结果

  delete first;
  delete second;
  delete ret;
}

vector<int> p1_0_0{1, 2, 4};
vector<int> p1_1_0{1, 3, 4};
ListNode* p1_0 = construct_link_list<ListNode, int>(p1_0_0);
ListNode* p1_1 = construct_link_list<ListNode, int>(p1_1_0);
ArgumentType p1(p1_0, p1_1);
vector<int> r1_0{1, 1, 2, 3, 4, 4};
ResultType r1 = construct_link_list<ListNode, int>(r1_0);

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode21ParamTest, LeetCode21Test, values);

}
