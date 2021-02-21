//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2009.hpp"

namespace CIG_1_2009 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* findKthNode(ListNode* head, int i) {
  while (head) {
    if (--i == 0) return head;
    head = head->next;
  }
  return nullptr;
}

class CIG_1_2009_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2009_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2009::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int n, m;
  tie(n, m) = arguments;

  // 构建从 0 - n 的vector
  vector<int> args(n);
  iota(args.begin(), args.end(), 0);

  ListNode* head = construct_link_list<ListNode>(args);
  // 链接头尾, 构造成环形链表
  ListNode* tail = findKthNode(head, n);
  tail->next = head;

  ListNode* asserted = findKthNode(head, ret);

  ASSERT_EQ(solution->josephusKill(head, m), asserted);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(5, 3), 4),  // 最后返回的值是 3, 也即第 4 个元素
  ParamType(ArgumentType(10, 17), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2009_ParamTest, CIG_1_2009_Test, values);

}