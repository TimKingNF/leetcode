//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_27.er-cha-shu-de-jing-xiang-lcof.h"

namespace LeetCode_27 {

typedef pair<vector<int>, vector<int>> ArgumentType;
// typedef ArgumentType ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_27Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_27Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_27::Solution();
  ArgumentType argument = GetParam();

  TreeNode* root = build_tree<TreeNode, int>(argument.first, argument.second);
  TreeNode* mirrorRoot = solution->mirrorTree(root);
  TreeNode* mirror2Root = solution->mirrorTree(mirrorRoot);  // mirror2Root -> root
  TreeNode* assert_root = build_tree<TreeNode, int>(argument.first, argument.second);

  // 镜像翻转两次结果应当不变
  vector<int> preorder_root = preorder_range_binary_tree<TreeNode, int>(assert_root);
  vector<int> preorder_mirror2_root = preorder_range_binary_tree<TreeNode, int>(mirror2Root);
  ASSERT_EQ(preorder_root, preorder_mirror2_root);

  vector<int> inorder_root = inorder_range_binary_tree<TreeNode, int>(assert_root);
  vector<int> inorder_mirror2_root = inorder_range_binary_tree<TreeNode, int>(mirror2Root);
  ASSERT_EQ(inorder_root, inorder_mirror2_root);

  delete root;
  delete assert_root;
}

vector<int> p1_0{4, 2, 1, 3, 7, 6, 9};
vector<int> p1_1{1, 2, 3, 4, 6, 7, 9};
ArgumentType p1(p1_0, p1_1);

vector<int> p2_0{1, 2};
vector<int> p2_1{2, 1};
ArgumentType p2(p2_0, p2_1);

auto values = ::testing::Values(
  p1,
  p2
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_27ParamTest, LeetCode_27Test, values);

}
