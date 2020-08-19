//给定一组 互不相同 的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。 
//
// 
//
// 示例 1： 
//
// 输入：["abcd","dcba","lls","s","sssll"]
//输出：[[0,1],[1,0],[3,2],[2,4]] 
//解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
// 
//
// 示例 2： 
//
// 输入：["bat","tab","cat"]
//输出：[[0,1],[1,0]] 
//解释：可拼接成的回文串为 ["battab","tabbat"] 
// Related Topics 字典树 哈希表 字符串

#include "header.h"

namespace LeetCode336 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode*> dict;
    int idx = -1;  // 互不相同，所以无需用 vector<int> 保存
    ~TrieNode() { for (auto v : dict) delete v.second; }
  };

  // 将插入的字符串，反转加入字典树
  class ReverseTrie {
   public:
    TrieNode *root;
    ReverseTrie() { root = new TrieNode; }
    ~ReverseTrie() { delete root; }

    void insert(string word, int idx) {
      TrieNode *cur = root;
      for (int i = word.size()-1; i >= 0; --i) {
        if (!cur->dict.count(word[i])) cur->dict[word[i]] = new TrieNode;
        cur = cur->dict[word[i]];
      }
      cur->idx = idx;
    }

    void matchPalindrome(string word, vector<int>& matchIdxs) {
      TrieNode *cur = root;
      // 判断是否存在 "" 且 word 本身为回文
      if (root->idx != -1 && isPalindrome(word)) {
        matchIdxs.push_back(root->idx);
      }

      int n = word.size(), i = 0;
      for (; i < word.size(); ++i) {
        if (!cur->dict.count(word[i])) break;  // 不匹配的话，遍历到此结束
        cur = cur->dict[word[i]];
        // 有一个节点符合，且 word 剩下的字符串是回文
        if (cur->idx != -1 && isPalindrome(word, i+1, n-1)) {
          matchIdxs.push_back(cur->idx);
        }
      }

      if (i == n) {
        // 在 word 可以遍历完的情况下继续往下探，需要考虑 cur 接下来的字符是否构成回文字符串
        for (auto v : cur->dict) {
          string path;
          path += v.first;
          matchPalindrome(v.second, path, matchIdxs);
        }
      }
    }

    bool isPalindrome(string& word) {
      return isPalindrome(word, 0, word.size()-1) ;
    }

    bool isPalindrome(string& word, int i, int j) {
      while (i <= j) {
        if (word[i] != word[j]) return false;
        ++i;
        --j;
      }
      return true;
    }

    void matchPalindrome(TrieNode* node, string path, vector<int>& matchIdxs) {
      if (!node) return;

      // 在某个节点处，剩下的字符串构成回文字符串
      if (node->idx != -1 && isPalindrome(path)) {
        matchIdxs.push_back(node->idx);
      }
      // 接着下探直到叶子节点
      for (auto v : node->dict)
        matchPalindrome(v.second, path + v.first, matchIdxs);
    }
  };
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      return solution1(words);
    }

    vector<vector<int>> solution1(vector<string>& words) {
      if (words.empty()) return {};
      vector<vector<int>> ans;
      ReverseTrie *trie = new ReverseTrie;
      // 将字符串加入到前缀树中
      for (int i = 0; i < words.size(); ++i) trie->insert(words[i], i);

      vector<int> matchIdxs;
      for (int i = 0; i < words.size(); ++i) {
        matchIdxs.clear();
        trie->matchPalindrome(words[i], matchIdxs);
        for (auto v : matchIdxs) {
          if (i != v) ans.push_back({i, v});  // 两个下标不能相同
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}