//在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，
//跟随着单词 other(其他)，可以形成新的单词 another(另一个)。 
//
// 现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。 
//
// 你需要输出替换之后的句子。 
//
// 
//
// 示例： 
//
// 输入：dict(词典) = ["cat", "bat", "rat"] sentence(句子) = "the cattle was rattled by
// the battery"
//输出："the cat was rat by the bat"
// 
//
// 
//
// 提示： 
//
// 
// 输入只包含小写字母。 
// 1 <= dict.length <= 1000 
// 1 <= dict[i].length <= 100 
// 1 <= 句中词语数 <= 1000 
// 1 <= 句中词语长度 <= 1000 
// 
// Related Topics 字典树 哈希表

#include "header.h"

namespace LeetCode648 {

//leetcode submit region begin(Prohibit modification and deletion)
class Trie {
  struct Node {
    bool end = false;
    unordered_map<char, Node*> dict;
  };

 private:
  Node* root;

 public:
  Trie() { root = new Node; }

  void insert(string word) {
    Node* cur = root;
    for (char c : word) {
      if (!cur->dict.count(c)) cur->dict[c] = new Node;
      cur = cur->dict[c];
    }
    cur->end = true;  // 表示是一个有效单词
  }

  string matchPrefix(string word) {
    Node* cur = root;
    int n = word.size();
    for (int i = 0; i < n; ++i) {
      if (!cur->dict.count(word[i])) return word;
      cur = (cur->dict)[word[i]];
      if (cur->end) return word.substr(0, i+1);  // 能匹配上则取最短
    }
    return word;
  }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
      return solution1(dict, sentence);
    }

    // 词根从首字母开始，不存在在单词后面的情况
    string solution1(vector<string>& dict, string sentence) {
      if (dict.empty()) return sentence;
      Trie* trie = new Trie;
      for (auto& v : dict) trie->insert(v);
      istringstream input(sentence);
      ostringstream os;
      string word;
      while (getline(input, word, ' ')) {
        os << trie->matchPrefix(word) << ' ';
      }
      word = os.str();
      return word.substr(0, word.size()-1);  // 去掉最后一个空格
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}