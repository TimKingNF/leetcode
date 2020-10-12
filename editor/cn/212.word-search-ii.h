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
    bool isEnd = false;
    string word;
    ~TrieNode() { for (auto v : dict) delete v.second; }
  };

  class Trie {
   public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    ~Trie() { delete root; }
    void insert(string word) {
      TrieNode* cur = root;
      for (char c : word) {
        if (!cur->dict.count(c)) cur->dict[c] = new TrieNode();
        cur = cur->dict[c];
      }
      cur->isEnd = true;
      cur->word = word;  // 记录下本单词
    }
  };
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (words.empty() || board.empty() || board[0].empty()) return {};

    // 构造前缀树
    Trie* trie = new Trie;
    for (auto v : words) trie->insert(v);

    set<string> ans;
    int rows = board.size(), cols = board[0].size();

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        match(board, trie->root, r, c, ans);
      }
    }
    return vector<string>{ans.begin(), ans.end()};  // 避免重复出现
  }

  void match(vector<vector<char>>& board, TrieNode* node, int r, int c, set<string>& ans) {
    int rows = board.size(), cols = board[0].size();
    // 越界或者已经访问过
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == '/') return;
    if (!node->dict.count(board[r][c])) return;  // 剪枝

    char orig = board[r][c];
    // end 条件
    if (node->dict[orig]->isEnd) {
      ans.insert(node->dict[orig]->word);
      // 不能提前结束，也许存在 某个单词是另一个单词的前缀
    }

    board[r][c] = '/';
    // 继续下探四周
    match(board, node->dict[orig], r - 1, c, ans);
    match(board, node->dict[orig], r + 1, c, ans);
    match(board, node->dict[orig], r, c - 1, ans);
    match(board, node->dict[orig], r, c + 1, ans);
    board[r][c] = orig;  // 恢复原状
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}