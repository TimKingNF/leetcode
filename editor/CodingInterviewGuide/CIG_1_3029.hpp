//
// Created by timking.nf@foxmail.com on 2021/2/26.
//

#ifndef LEETCODE_CIG_1_3029_HPP
#define LEETCODE_CIG_1_3029_HPP

#include "header.h"

namespace CIG_1_3029 {

class Solution {
 public:
  vector<int> getPostOrder(vector<int>& preOrder, vector<int>& inOrder) {
    if (preOrder.empty() || inOrder.empty()) return {};
    int len = preOrder.size();
    vector<int> postOrder(len);
    // 构建一个字典
    unordered_map<int, int> dict;
    for (int i = 0; i < len; ++i) {
      dict.insert({inOrder[i], i});
    }
    setPost(preOrder, 0, len-1, inOrder, 0, len-1, dict, postOrder, len-1);
    return postOrder;
  }

  // 返回值 是下一个应该填根节点的位置
  int setPost(vector<int>& preOrder, int preStart, int preEnd,
               vector<int>& inOrder, int inStart, int inEnd,
               unordered_map<int, int>& dict,
               vector<int>& postOrder, int postEnd) {
    if (preStart > preEnd || inStart > inEnd) return postEnd;
    // 根节点
    postOrder[postEnd--] = preOrder[preStart];
    int leftCount = dict[preOrder[preStart]] - inStart;  // 以 preStart 为根，找到左子树的个数
    // 先计算右子树, 因为后序遍历，下一个要填的 postEnd 的位置是右子树的值
    postEnd = setPost(preOrder, preStart+leftCount+1, preEnd,
                      inOrder, inStart+leftCount+1, inEnd,
                      dict, postOrder, postEnd);
    return setPost(preOrder, preStart+1, preStart+leftCount,
                   inOrder, inStart, inStart+leftCount-1,
                   dict, postOrder, postEnd);
  }
};

}

#endif  // LEETCODE_CIG_1_3029_HPP
