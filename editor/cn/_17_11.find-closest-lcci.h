//有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，
//你能对此优化吗? 
//
// 示例： 
//
// 输入：words = ["I","am","a","student","from","a","university","in","a","city"], 
//word1 = "a", word2 = "student"
//输出：1 
//
// 提示： 
//
// 
// words.length <= 100000 
// 
// Related Topics 双指针 字符串 
// 👍 21 👎 0

#include "header.h"

namespace LeetCode_17_11 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
      return solution1(words, word1, word2);
    }

    // 普通解法
    int solution1(vector<string>& words, string word1, string word2) {
      int last1 = -1, last2 = -1;
      int ans = INT32_MAX;
      for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1) {
          ans = min(ans, last2 == -1 ? INT32_MAX : i - last2);
          last1 = i;
        } else if (words[i] == word2) {
          ans = min(ans, last1 == -1 ? INT32_MAX : i - last1);
          last2 = i;
        }
      }
      return ans == INT32_MAX ? -1 : ans;
    }

    // 多次查询优化解法, 缓存所有单词之间的距离 ( 会超时 )
    int solution2(vector<string>& words, string word1, string word2) {
      unordered_map<string, unordered_map<string, int>> dict;
      int n = words.size();
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          if (words[i] == words[j]) continue;  // 自己和自己无需讨论
          auto items = dict.count(words[i]) ? dict[words[i]] : unordered_map<string, int>{};
          if (items.count(words[j])) {
            dict[words[j]][words[i]] = items[words[j]] = min(j-i, items[words[j]]);
          } else {
            if (!dict.count(words[j])) dict[words[j]] = {{words[i], 0}};
            if (!dict[words[j]].count(words[i])) dict[words[j]][words[i]] = 0;
            dict[words[j]][words[i]] = items[words[j]] = j-i;
          }
          dict[words[i]] = items;
        }
      }

      return dict[word1][word2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}