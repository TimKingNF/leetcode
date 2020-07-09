//
// Created by timking.nf@foxmail.com on 2020/5/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_18.shan-chu-lian-biao-de-jie-dian-lcof.h"

namespace LeetCode_18 {

typedef tuple<ListNode*, int> ArgumentType;
typedef ListNode* ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_18Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_18Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_18::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ListNode* head;
  int val;
  tie(head, val) = arguments;

  ASSERT_TRUE(link_list_cmp(solution->deleteNode(head, val), ret));

  // 清理指针
  delete head;
  delete ret;
}

vector<int> p1_0{4,5,1,9};
ArgumentType p1(construct_link_list<ListNode, int>(p1_0), 5);

ArgumentType p2(construct_link_list<ListNode, int>(p1_0), 1);

vector<int> r1_0{4,1,9};
ResultType r1 = construct_link_list<ListNode, int>(r1_0);

vector<int> r2_0{4,5,9};
ResultType r2 = construct_link_list<ListNode, int>(r2_0);

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_18ParamTest, LeetCode_18Test, values);

}
