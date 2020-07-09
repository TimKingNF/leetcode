//
// Created by timking.nf@foxmail.com on 2020/5/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "206.reverse-linked-list.h"

namespace LeetCode206 {

typedef ListNode* ArgumentType;
typedef ListNode* ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode206Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode206Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode206::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_TRUE(link_list_cmp(solution->reverseList(argument), ret));  // 断言结果

  delete argument;
  delete ret;
}

vector<int> p1_0{1, 2, 3, 4, 5};
ListNode* p1 = construct_link_list<ListNode, int>(p1_0);
vector<int> r1_0{5, 4, 3, 2, 1};
ResultType r1 = construct_link_list<ListNode, int>(r1_0);

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode206ParamTest, LeetCode206Test, values);

}