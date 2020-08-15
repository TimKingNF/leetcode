//
// Created by timking.nf@foxmail.com on 2020/8/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "23.merge-k-sorted-lists.h"

namespace LeetCode23 {

typedef vector<vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode23Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode23Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode23::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<ListNode*> lists;
  for (auto v : argument) lists.push_back(construct_link_list<ListNode>(v));
  ListNode* assertedHead = solution->mergeKLists(lists);
  ListNode* resultHead = construct_link_list<ListNode>(ret);
  ASSERT_TRUE(link_list_cmp(resultHead, assertedHead));
}

auto values = ::testing::Values(
  ParamType({{1,4,5}, {1,3,4}, {2,6}}, {1,1,2,3,4,4,5,6}),
  ParamType({{}}, {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode23ParamTest, LeetCode23Test, values);

}