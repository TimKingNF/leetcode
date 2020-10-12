//给一非空的单词列表，返回前 k 个出现次数最多的单词。 
//
// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。 
//
// 示例 1： 
//
// 
//输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出: ["i", "love"]
//解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//    注意，按字母顺序 "i" 在 "love" 之前。
// 
//
// 
//
// 示例 2： 
//
// 
//输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k
// = 4
//输出: ["the", "is", "sunny", "day"]
//解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//    出现次数依次为 4, 3, 2 和 1 次。
// 
//
// 
//
// 注意： 
//
// 
// 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。 
// 输入的单词均由小写字母组成。 
// 
//
// 
//
// 扩展练习： 
//
// 
// 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。 
// 
// Related Topics 堆 字典树 哈希表

#include "header.h"

namespace LeetCode692 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      return solution1(words, k);
    }

    // 桶排序
    vector<string> solution1(vector<string>& words, int k) {
      // 先计算频率
      unordered_map<string, int> dict;
      for (auto v : words) dict[v]++;

      int n = words.size();
      // 二维数组，将同一频率的字符串放在一起
      vector<vector<string>> buckets(n + 1, vector<string>());
      for (auto v : dict) buckets[v.second].push_back(v.first);

      vector<string> ans(k);
      int count = 0;
      for (int i = n; i >= 0; --i) {  // i 是 频率
        if (buckets[i].size() > 0) {
          sort(buckets[i].begin(), buckets[i].end());  // 同一频率按字符顺序排序
          for (int j = 0; j < buckets[i].size(); ++j) {
            ans[count] = buckets[i][j];
            if (++count == k) return ans;
          }
        }
      }
      return ans;
    }

    // 堆排序也可
};
//leetcode submit region end(Prohibit modification and deletion)

}