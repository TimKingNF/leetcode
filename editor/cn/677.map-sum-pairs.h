//实现一个 MapSum 类里的两个方法，insert 和 sum。 
//
// 对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。 
//
// 对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。 
//
// 示例 1: 
//
// 输入: insert("apple", 3), 输出: Null
//输入: sum("ap"), 输出: 3
//输入: insert("app", 2), 输出: Null
//输入: sum("ap"), 输出: 5
// 
// Related Topics 字典树

#include "header.h"

namespace LeetCode677 {

//leetcode submit region begin(Prohibit modification and deletion)
struct TrieNode {
  int val = 0;
  unordered_map<char, TrieNode*> dict;
};

class MapSum {
 private:
  TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
      root = new TrieNode();
    }
    
    void insert(string key, int val) {
      TrieNode* cur = root;
      for (char c : key) {
        if (!cur->dict.count(c)) cur->dict[c] = new TrieNode;
        cur = cur->dict[c];
      }
      // 记录key值
      cur->val = val;
    }
    
    int sum(string prefix) {
      TrieNode* cur = root;
      for (char c : prefix) {
        if (!cur->dict.count(c)) return 0;  // 说明没有此前缀的单词
        cur = cur->dict[c];
      }
      // dfs 遍历 cur 下的所有的节点的值
      int ans = 0;
      function<void(TrieNode*)> dfs = [&](TrieNode* node) {
        if (!node) return;
        ans += node->val;
        for (auto v : node->dict) dfs(v.second);
      };
      dfs(cur);
      return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)

}