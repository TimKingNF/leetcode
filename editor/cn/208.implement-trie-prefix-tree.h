//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。 
//
// 示例: 
//
// Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");   
//trie.search("app");     // 返回 true 
//
// 说明: 
//
// 
// 你可以假设所有的输入都是由小写字母 a-z 构成的。 
// 保证所有输入均为非空字符串。 
// 
// Related Topics 设计 字典树

#include "header.h"

namespace LeetCode208 {

//leetcode submit region begin(Prohibit modification and deletion)
struct TrieNode {
  // 也可以改用数组存储
  unordered_map<char, TrieNode*> dict;
  char val;
  bool isWord;
  explicit TrieNode(char val) : val(val), isWord(false) {};
  TrieNode(char val, bool isWord) : val(val), isWord(isWord) {};
};

// 时间复杂度都是 O( N )
// 空间复杂度 O( M*N*K ), M 是总共有多少个单词，N 是最长长度，K 是字符不同数，本题中为 26
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
      root = new TrieNode(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      TrieNode* cur = root;
      for (char c : word) {
        if (!cur->dict.count(c)) {
          cur->dict[c] = new TrieNode(c);
        }
        cur = cur->dict[c];
      }
      // cur 指在最后一个字符。记录它是一个单词
      cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      TrieNode* cur = root;
      for (char c : word) {
        if (!cur->dict.count(c)) return false;
        cur = cur->dict[c];
      }
      return cur->isWord;  // 最后一个字符，判断其是否有效单词
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      TrieNode* cur = root;
      for (char c : prefix) {
        if (!cur->dict.count(c)) return false;
        cur = cur->dict[c];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)

}