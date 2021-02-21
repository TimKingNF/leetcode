//
// Created by timking.nf@foxmail.com on 2021/2/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "449.serialize-and-deserialize-bst.h"

namespace LeetCode449 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode449Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode449Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  Codec codec;
  ArgumentType argument = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  TreeNode* copyRoot = codec.deserialize(codec.serialize(root));

  // 使用前序和中序校验两树是否相同
  vector<int> preorder_root = preorder_range_binary_tree<TreeNode, int>(root);
  vector<int> preorder_copy_root = preorder_range_binary_tree<TreeNode, int>(copyRoot);
  vector<int> inorder_root = inorder_range_binary_tree<TreeNode, int>(root);
  vector<int> inorder_copy_root = inorder_range_binary_tree<TreeNode, int>(copyRoot);
  ASSERT_EQ(preorder_root, preorder_copy_root);
  ASSERT_EQ(inorder_root, inorder_copy_root);
}

auto values = ::testing::Values(
  "",
  "2,1,3",
  "3,1,5,null,2,4,6"
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode449ParamTest, LeetCode449Test, values);

}