//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_02_03.delete-middle-node-lcci.h"

namespace LeetCode_02_03 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* findDelNode(ListNode* head, int v) {
  if (!head) return nullptr;
  while (head) {
    if (head->val == v) return head;
    head = head->next;
  }
  return nullptr;
}

class LeetCode_02_03Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_02_03Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_02_03::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int v;
  tie(args, v) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* asserted = construct_link_list<ListNode>(ret);
  ListNode* delNode = findDelNode(head, v);
  solution->deleteNode(delNode);  // 只能访问该节点
  ASSERT_TRUE(link_list_cmp(head, asserted));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 3), {1,2,4,5}),
  ParamType(ArgumentType({1,2,3,4,5,6}, 4), {1,2,3,5,6})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_02_03ParamTest, LeetCode_02_03Test, values);

}