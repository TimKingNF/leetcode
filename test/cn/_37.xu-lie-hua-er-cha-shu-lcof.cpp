//
// Created by timking.nf@foxmail.com on 2020/6/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_37.xu-lie-hua-er-cha-shu-lcof.h"

namespace LeetCode_37 {

typedef string ArgumentType;
// typedef vector<int> ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_37Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_37Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  Codec codec;
  ArgumentType argument = GetParam();

  TreeNode* root = buildTreeBySerialize<TreeNode>(argument);
  TreeNode* copyRoot = codec.deserialize(codec.serialize(root));

  vector<int> preorder_root = preorder_range_binary_tree<TreeNode, int>(root);
  vector<int> preorder_copy_root = preorder_range_binary_tree<TreeNode, int>(copyRoot);
  vector<int> inorder_root = inorder_range_binary_tree<TreeNode, int>(root);
  vector<int> inorder_copy_root = inorder_range_binary_tree<TreeNode, int>(copyRoot);
  ASSERT_EQ(preorder_root, preorder_copy_root);
  ASSERT_EQ(inorder_root, inorder_copy_root);
}

auto values = ::testing::Values(
  "1,2,3,null,null,4,5"
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_37ParamTest, LeetCode_37Test, values);

}