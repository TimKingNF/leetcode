//给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
// 
//
// 示例: 
//
// 输入: 
//words = ["oath","pea","eat","rain"] and board =
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]
//
//输出: ["eat","oath"] 
//
// 说明: 
//你可以假设所有输入都由小写字母 a-z 组成。 
//
// 提示: 
//
// 
// 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？ 
// 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何
//实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。 
// 
// Related Topics 字典树 回溯算法

#include "header.h"

namespace LeetCode212 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode*> dict;
    bool end = false;
    ~TrieNode() { for (auto v : dict) delete v.second; }
  };

  class Trie {
   public:
    TrieNode* root;
    ~Trie() { delete root; }
    Trie() { root = new TrieNode; }
    void insert(string word) {
      TrieNode* cur = root;
      for (char c : word) {
        if (!cur->dict.count(c)) cur->dict[c] = new TrieNode;
        cur = cur->dict[c];
      }
      cur->end = true;
    }
  };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      return solution1(board, words);
    }

    bool match(vector<vector<char>>& board, vector<bool>& visited,
               int curY, int curX,
               TrieNode* node,
               string path, vector<string>& paths) {
      int rows = board.size(), cols = board[0].size();
      int idx = curY * cols + curX;  // 计算 visited 的索引
      char c = board[curY][curX];
      if (visited[idx]) return false;  // 已经访问过
      if (!node->dict.count(c)) return false;  // 当前字符不满足字典树前缀

      path += c;
      visited[idx] = true;  // 记录已经访问过
      int cnt = 0;  // 在遍历过程中满足符合words 的数量
      // 需要遍历到所有的根节点位置

      if (node->dict[c]->end) {
        cnt++;
        paths.push_back(path);  // 说明在查找的过程中满足了一次结果
      }

      // 往上下左右嗅探
      if (curY - 1 >= 0)
        cnt += (int) match(board, visited, curY - 1, curX, node->dict[c], path, paths);
      if (curY + 1 < rows)
        cnt += (int) match(board, visited, curY + 1, curX, node->dict[c], path, paths);
      if (curX - 1 >= 0)
        cnt += (int) match(board, visited, curY, curX - 1, node->dict[c], path, paths);
      if (curX + 1 < cols)
        cnt += (int) match(board, visited, curY, curX + 1, node->dict[c], path, paths);

      visited[idx] = false;  // 还原状态
      return cnt > 0;
    }

    // 利用前缀树解法
    vector<string> solution1(vector<vector<char>>& board, vector<string>& words) {
      if (words.empty()) return {};
      int rows = board.size(), cols = board[0].size();

      set<string> ans;
      Trie* trie = new Trie;
      for (auto& word : words) trie->insert(word);
      vector<bool> visited(rows*cols, false);  // 记录是否被访问过
      vector<string> paths;

      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          // 能匹配就说明该字符符合字符串的第一个字符，否则就剪枝
          paths.clear();
          if (match(board, visited, r, c, trie->root, "", paths)) {
            for (auto& v : paths) ans.insert(v);
            visited = vector<bool>(rows*cols, false);  // 重置状态
          }
        }
      }
      return vector<string>(ans.begin(), ans.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}