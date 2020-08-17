//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "226.invert-binary-tree.h"

namespace LeetCode226 {

typedef string ArgumentType;
// typedef ArgumentType ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode226Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode226Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode226::Solution();
  ArgumentType argument = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  TreeNode* mirrorRoot = solution->invertTree(root);
  TreeNode* asserted_root = solution->invertTree(mirrorRoot);  // mirror2Root -> root
  TreeNode* result_root = buildTreeBySerialize<TreeNode>(argument);

  // 镜像翻转两次结果应当不变
  vector<int> preorder_asserted_root = preorder_range_binary_tree<TreeNode, int>(asserted_root);
  vector<int> preorder_result_root = preorder_range_binary_tree<TreeNode, int>(result_root);
  ASSERT_EQ(preorder_asserted_root, preorder_result_root);

  vector<int> inorder_asserted_root = inorder_range_binary_tree<TreeNode, int>(asserted_root);
  vector<int> inorder_result_root = inorder_range_binary_tree<TreeNode, int>(result_root);
  ASSERT_EQ(inorder_asserted_root, inorder_result_root);
}

auto values = ::testing::Values(
  "4,2,7,1,3,6,9",
  "1,2"
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode226ParamTest, LeetCode226Test, values);

}
