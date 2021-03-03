//
// Created by timking.nf@foxmail.com on 2021/2/24.
//

#ifndef LEETCODE_CIG_1_3018_HPP
#define LEETCODE_CIG_1_3018_HPP

#include "header.h"

namespace CIG_1_3018 {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  bool isPostArray(vector<int>& arr) {
    if (arr.empty()) return true;
    return isPost(arr, 0, arr.size()-1);
  }

  bool isPost(vector<int>& arr, int start, int end) {
    if (start >= end) return true;
    // 头节点是 end
    int head = arr[end];
    // 从 start - end 处找连续小于 head 的边界
    int i = start;
    while (i < end && arr[i] < head) ++i;
    int less = i;
    // [start, less) 处是小于 head 的, 校验 [less, end) 所有值都应大于 head
    for (i = less; i < end; ++i) {
      if (arr[i] < head) return false;
    }
    return isPost(arr, start, less-1) && isPost(arr, less, end-1);
  }

  TreeNode* postToBST(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;
    TreeNode* node = new TreeNode(arr[end]);
    int less = start;
    while (less < end && arr[less] < arr[end]) ++less;
    node->left = postToBST(arr, start, less-1);
    node->right = postToBST(arr, less, end-1);
    return node;
  }

 public:
  TreeNode* postArrayToBST(vector<int>& arr) {
    if (arr.empty() || !isPostArray(arr)) return nullptr;
    return postToBST(arr, 0, arr.size()-1);
  }
};

}

#endif  // LEETCODE_CIG_1_3018_HPP
