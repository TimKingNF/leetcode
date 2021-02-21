//给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
// 
//
// 注意：字符串长度 和 k 不会超过 104。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ABAB", k = 2
//输出：4
//解释：用两个'A'替换为两个'B',反之亦然。
// 
//
// 示例 2： 
//
// 
//输入：s = "AABABBA", k = 1
//输出：4
//解释：
//将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
//子串 "BBBB" 有最长重复字母, 答案为 4。
// 
// Related Topics 双指针 Sliding Window 
// 👍 322 👎 0

#include "header.h"

namespace LeetCode424 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int characterReplacement(string s, int k) {
      return solution1(s, k);
    }

    // 参考此说明：
    // https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/dong-hua-mo-ni-yao-shi-kan-bu-dong-jiu-g-4rpi/
    int solution1(string s, int k) {
      int n = s.size();
      int dict[26] = {0};
      int cnt = 0;  // 记录窗口中曾出现的某个字符的大小

      int i = 0;
      for (int j = 0; j < n; ++j) {
        ++dict[s[j] - 'A'];
        cnt = max(cnt, dict[s[j] - 'A']);  // 求得出现某个字符的最大大小

        // j-i+1 即窗口长度
        // 窗口长度 - 某个字符出现的最多次数，即 剩下的字符需要变的次数 超过了 K
        if (j - i + 1 - cnt > k) {  // 窗口需要缩小
          --dict[s[i] - 'A'];  // 窗口越过该点
          ++i;
        }
        // 如果小于等于 k，也即说明 窗口在 i 不动的情况下，还可以继续扩大
        // 从而不断的撑大窗口
      }
      return n - i;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}