//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_02_02.kth-node-from-end-of-list-lcci.h"

namespace LeetCode_02_02 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_02_02Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_02_02Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_02_02::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> list;
  int k;
  tie(list, k) = arguments;

  ListNode* head = construct_link_list<ListNode>(list);
  ASSERT_EQ(solution->kthToLast(head, k), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 2), 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_02_02ParamTest, LeetCode_02_02Test, values);

}