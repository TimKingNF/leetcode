// 本质是 _34.er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof.h 的变种
// 但要注意的是 这里指的路径是 从任一节点开始，而非根节点
// 也即要求解以每个节点为结尾的情况下，累加和为 sum 的情况
//
// Created by timking.nf@foxmail.com on 2021/2/21.
//

#ifndef LEETCODE_CIG_1_3009_HPP
#define LEETCODE_CIG_1_3009_HPP

#include "header.h"

namespace CIG_1_3009 {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int getMaxLength(TreeNode* root, int sum) {
    unordered_map<int, int> sumMap;
    sumMap.insert({0, 0});
    return preOrder(root, sum, 0, 1, 0, sumMap);
  }

  int preOrder(TreeNode* node, int sum, int preSum, int level, int maxLen,
               unordered_map<int, int>& sumMap) {
    if (!node) return maxLen;
    int curSum = preSum + node->val;  // 加上本次遍历到的点的值
    if (!sumMap.count(curSum)) {  // 说明该值不在上层节点出现过
      sumMap.insert({curSum, level});  // 记录当前值和 level
    }
    if (sumMap.count(curSum - sum)) {
      // 如果这一步存在, 说明有从某个节点到 cur 节点的距离为 sum, 则需计算最大距离
      maxLen = max(level - sumMap[curSum-sum], maxLen);
    }
    // 计算左子树和右子树, 注意 maxLen 是一直被更新的
    maxLen = preOrder(node->left, sum, curSum, level+1, maxLen, sumMap);
    maxLen = preOrder(node->right, sum, curSum, level+1, maxLen, sumMap);
    // 如果 sumMap[curSum] == level, 说明在考虑 cur 左右子树之后，
    // curSum 不再为 路径上可以作为计算的点
    // 该记录是在遍历cur的时候添加上去的，为了避免对 cur 及其子树以外的子树造成影响，此时需要移除
    // （ 如果不等于 level, 说明 curSum 对应的 level 还在 cur 的上级节点处, 需要参与计算 ）
    if (level == sumMap[curSum]) {
      sumMap.erase(curSum);
    }
    return maxLen;
  }
};

}

#endif  // LEETCODE_CIG_1_3009_HPP
