//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2018.hpp"

namespace CIG_1_2018 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

// 验证是否有效的双向链表
bool validDoubleLinkedList(TreeNode* head) {
  if (!head) return true;
  if (head->left) return false;
  TreeNode *pre = new TreeNode(0), *origHead = head;
  pre->right = head;
  head->left = pre;
  while (head) {
    if (head->left != pre) return false;
    if (pre->right != head) return false;
    pre = head;
    head = head->right;
  }
  origHead->left = nullptr;  // 恢复原状
  return true;
}

TreeNode* construct_link_list(vector<int>& input_list) {
  if (input_list.empty()) return nullptr;

  TreeNode* head = new TreeNode(input_list[0]);
  TreeNode* tmp = head;
  TreeNode* new_node;
  for (int i = 1; i < input_list.size(); ++i) {
    new_node = new TreeNode(input_list[i]);
    tmp->right = new_node;
    tmp = new_node;
  }
  return head;
}

bool link_list_cmp(TreeNode* first, TreeNode* second) {
  while (first != nullptr && second != nullptr) {
    if (first->val != second->val) return false;
    first = first->right;
    second = second->right;
  }
  return first == nullptr && second == nullptr;  // 两个都为空指针时，说明比较完毕，两个链表值相同
}

void link_list_print(TreeNode* root) {
  while (root) {
    cout << root->val << "->";
    root = root->right;
  }
  cout << endl;
}

class CIG_1_2018_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2018_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2018::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  TreeNode* result = construct_link_list(ret);
  TreeNode* asserted = solution->convert(root);
  // link_list_print(asserted);
  ASSERT_TRUE(validDoubleLinkedList(asserted));
  ASSERT_TRUE(link_list_cmp(result, asserted));
}

auto values = ::testing::Values(
  ParamType("6,4,7,2,5,null,9,1,3,null,null,8", {1,2,3,4,5,6,7,8,9})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2018_ParamTest, CIG_1_2018_Test, values);

}