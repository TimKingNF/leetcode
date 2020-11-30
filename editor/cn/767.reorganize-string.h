//给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。 
//
// 若可行，输出任意可行的结果。若不可行，返回空字符串。 
//
// 示例 1: 
//
// 
//输入: S = "aab"
//输出: "aba"
// 
//
// 示例 2: 
//
// 
//输入: S = "aaab"
//输出: ""
// 
//
// 注意: 
//
// 
// S 只包含小写字母并且长度在[1, 500]区间内。 
// 
// Related Topics 堆 贪心算法 排序 字符串 
// 👍 172 👎 0

#include "header.h"

namespace LeetCode767 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reorganizeString(string S) {
      return solution2(S);
    }

    string solution1(string S) {
      int n = S.size();
      int dict[26] = {0};
      for (auto c : S) dict[c-'a']++;
      priority_queue<pair<int, char>, vector<pair<int, char>>, less<>> pq;
      for (int i = 0; i < 26; ++i) {
        if (dict[i] != 0) pq.push({dict[i], 'a' + i});
      }

      auto pop_char = [&](char prev) {
        if (pq.empty()) return '\0';
        auto top = pq.top();
        pq.pop();
        if (top.second != prev) {
          if (--top.first > 0) pq.push(top);
          return top.second;
        }
        if (pq.empty()) return '\0';  // 说明除了相同的字符，后续再也没有字符可以取
        auto second = pq.top();
        pq.pop();
        if (--second.first > 0) pq.push(second);
        pq.push(top);
        return second.second;
      };

      ostringstream oss;
      char prev = '\0';
      char c = pop_char(prev);
      while (c != '\0') {
        oss << c;
        c = pop_char(c);
      }
      string ans = oss.str();
      return ans.size() != n ? "" : ans;
    }

    // 基于计数的贪心算法
    string solution2(string S) {
      if (S.size() < 2) return S;
      int counts[26] = {0};
      int maxCount = 0, n = S.size();
      for (auto c : S) {
        counts[c-'a']++;
        maxCount = max(maxCount, counts[c-'a']);
      }
      if (maxCount > (n + 1) / 2) return "";  // 如果单个元素的最大数量，超出了字符串的一半，则必定无解
      string reorganizeArray(n, ' ');
      int evenIdx = 0, oddIdx = 1;
      int halfLength = n / 2;

      // 循环尝试放置元素
      // 当 nn 是奇数且出现最多的字母的出现次数是 (n+1)/2 时，
      // 出现次数最多的字母必须全部放置在偶数下标，否则一定会出现相邻的字母相同的情况。
      for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        while (counts[i] > 0 && counts[i] <= halfLength && oddIdx < n) {
          reorganizeArray[oddIdx] = c;
          counts[i]--;
          oddIdx += 2;
        }
        while (counts[i] > 0) {
          reorganizeArray[evenIdx] = c;
          counts[i]--;
          evenIdx += 2;
        }
      }
      return reorganizeArray;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}