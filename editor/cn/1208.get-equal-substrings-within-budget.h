//给你两个长度相同的字符串，s 和 t。 
//
// 将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的
//绝对值。 
//
// 用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。 
//
// 如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。 
//
// 如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。 
//
// 
//
// 示例 1： 
//
// 输入：s = "abcd", t = "bcdf", cost = 3
//输出：3
//解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。 
//
// 示例 2： 
//
// 输入：s = "abcd", t = "cdef", cost = 3
//输出：1
//解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
// 
//
// 示例 3： 
//
// 输入：s = "abcd", t = "acde", cost = 0
//输出：1
//解释：你无法作出任何改动，所以最大长度为 1。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 10^5 
// 0 <= maxCost <= 10^6 
// s 和 t 都只含小写英文字母。 
// 
// Related Topics 数组 Sliding Window 
// 👍 101 👎 0

#include "header.h"

namespace LeetCode1208 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      return solution1(s, t, maxCost);
    }

    int solution1(string s, string t, int maxCost) {
      int cost = maxCost, n = s.size();
      int left = 0, right = 0;
      int ans = 0;

      while (right < n) {
        // 不满足 cost 足以让 right 往前走, 说明需要收 left
        int idx_cost = abs(s[right] - t[right]);
        while (left < right && idx_cost > cost) {
          cost += abs(s[left] - t[left]);
          ++left;
        }
        cost -= idx_cost;
        ans = max(ans, right - left + 1);
        ++right;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}