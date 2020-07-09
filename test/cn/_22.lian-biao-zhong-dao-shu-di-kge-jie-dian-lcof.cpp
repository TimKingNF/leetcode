//
// Created by timking.nf@foxmail.com on 2020/5/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_22.lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof.h"

namespace LeetCode_22 {

typedef tuple<ListNode*, int> ArgumentType;
typedef ListNode* ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_22Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_22Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_22::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ListNode* head;
  int k;
  tie(head, k) = arguments;

  ASSERT_TRUE(link_list_cmp(solution->getKthFromEnd(head, k), ret));  // 断言结果

  delete head;
  delete ret;
}

vector<int> p1_0_0{1, 2, 3, 4, 5};
ListNode* p1_0 = construct_link_list<ListNode, int>(p1_0_0);
ArgumentType p1(p1_0, 2);
vector<int> r1_0{4, 5};
ResultType r1 = construct_link_list<ListNode, int>(r1_0);

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_22ParamTest, LeetCode_22Test, values);

}
