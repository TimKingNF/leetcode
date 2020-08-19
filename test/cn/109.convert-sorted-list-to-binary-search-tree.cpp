//
// Created by timking.nf@foxmail.com on 2020/8/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "109.convert-sorted-list-to-binary-search-tree.h"

namespace LeetCode109 {

typedef vector<int> ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode109Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode109Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode109::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_link_list<ListNode>(argument);
  TreeNode* root = solution->sortedListToBST(head);
  string asserted = treeSerialize(root);

  // cout << asserted << endl;
  ASSERT_TRUE(ret.count(asserted));  // 断言结果
}

auto values = ::testing::Values(
  ParamType({}, {"null"}),
  ParamType({-10, -3, 0, 5, 9}, {"0,-3,9,-10,null,5"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode109ParamTest, LeetCode109Test, values);

}
