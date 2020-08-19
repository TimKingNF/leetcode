//给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。 
//
// 找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i, j < n 。 
//
// 你能在O(n)的时间解决这个问题吗？ 
//
// 示例: 
//
// 
//输入: [3, 10, 5, 25, 2, 8] 输出: 28
//解释: 最大的结果是 5 ^ 25 = 28.
//
// Related Topics 位运算 字典树

#include "header.h"

namespace LeetCode421 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 private:
  struct TrieNode {
    TrieNode* dict[2] = {nullptr, nullptr};
    ~TrieNode() {
      if (dict[0]) delete dict[0];
      if (dict[1]) delete dict[1];
    }

    TrieNode* insert(int idx) {
      if (!dict[idx]) dict[idx] = new TrieNode;
      return dict[idx];
    }
  };
public:
    int findMaximumXOR(vector<int>& nums) {
      return solution1(nums);
    }

    int solution1(vector<int>& nums) {
      TrieNode* trie = new TrieNode;
      int maxXor = 0;

      for (unsigned int num : nums) {
        TrieNode *node = trie, *xorNode = trie;
        int curXor = 0;
        for (int i = 30; i >= 0; --i) {
          int bitVal = (num >> i) & 1;  // 从第31位开始，取到对应位的值
          // 插入到前缀树中
          node = node->insert(bitVal);

          // 插入前缀树的同时计算在当前前缀树中的 maxXor
          // 先在对应的层级找是否有对应 toggle 字符，如果有则 curXor 则移位加1
          // 如果无，则说明 xor 该位为 0，然后继续往下找
          int toggleIdx = 1 - bitVal;
          if (xorNode->dict[toggleIdx]) {
            curXor = (curXor << 1) | 1;
            xorNode = xorNode->dict[toggleIdx];
          } else {
            curXor = curXor << 1;
            xorNode = xorNode->dict[bitVal];
          }
        }
        // word遍历完成的时候，同时也找到了当前前缀树中最大的 Xor
        maxXor = max(maxXor, curXor);
      }

      delete trie;
      return maxXor;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}