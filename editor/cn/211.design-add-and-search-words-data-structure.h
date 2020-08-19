//如果数据结构中有任何与word匹配的字符串，则bool search（word）返回true，否则返回false。 单词可能包含点“。” 点可以与任何字母匹
//配的地方。 
//
// 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。 
//
// 实现词典类 WordDictionary ： 
//
// 
// WordDictionary() 初始化词典对象 
// void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配 
// bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回 false 。word 中可能包含一些 '
//.' ，每个 . 都可以表示任何一个字母。 
// 
//
// 
//
// 示例： 
//
// 输入：
//["WordDictionary","addWord","addWord","addWord","search","search","search","se
//arch"]
//[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
//输出：
//[null,null,null,null,false,true,true,true]
//
//解释：
//WordDictionary wordDictionary = new WordDictionary();
//wordDictionary.addWord("bad");
//wordDictionary.addWord("dad");
//wordDictionary.addWord("mad");
//wordDictionary.search("pad"); // return False
//wordDictionary.search("bad"); // return True
//wordDictionary.search(".ad"); // return True
//wordDictionary.search("b.."); // return True
// 
//
// 
//
// 提示： 
//
// 
// 1 <= word.length <= 500 
// addWord 中的 word 由小写英文字母组成 
// search 中的 word 由 '.' 或小写英文字母组成 
// 最调用多 50000 次 addWord 和 search 
// 
// Related Topics 设计 字典树 回溯算法

#include "header.h"

namespace LeetCode211 {

//leetcode submit region begin(Prohibit modification and deletion)
class Trie {
 private:
  struct Node {
    bool end = false;
    unordered_map<char, Node*> dict;
    ~Node() {
      for (auto v : dict) delete v.second;
    }
  };
  Node* root = new Node;

 public:
  ~Trie() { delete root; }

  void insert(string word) {
    Node* cur = root;
    for (char c : word) {
      if (!cur->dict.count(c)) cur->dict[c] = new Node;
      cur = cur->dict[c];
    }
    cur->end = true;
  }

  bool search(Node* node, string& word, int start, int end) {
    for (int i = start; i <= end; ++i) {
      char c = word[i];
      if (c != '.') {
        if (!node->dict.count(c)) return false;
        node = node->dict[c];
      } else {
        // 为 . 则通用匹配, 这时候就相当于 break 最外层循环了
        for (auto v : node->dict) {
          // 从下个字符开始匹配
          if (search(v.second, word, i+1, end)) return true;
        }
        return false;  // 没有一个通用匹配可以符合
      }
    }
    return node->end;
  }

  bool search(string& word) {
    return search(root, word, 0, word.size()-1);
  }
};

class WordDictionary {
 private:
  Trie* trie;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
      trie = new Trie;
    }

    ~WordDictionary() {
      delete trie;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
      trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//leetcode submit region end(Prohibit modification and deletion)

}