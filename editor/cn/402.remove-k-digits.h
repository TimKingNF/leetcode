//给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。 
//
// 注意: 
//
// 
// num 的长度小于 10002 且 ≥ k。 
// num 不会包含任何前导零。 
// 
//
// 示例 1 : 
//
// 
//输入: num = "1432219", k = 3
//输出: "1219"
//解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
// 
//
// 示例 2 : 
//
// 
//输入: num = "10200", k = 1
//输出: "200"
//解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
// 
//
// 示例 3 : 
//
// 
//输入: num = "10", k = 2
//输出: "0"
//解释: 从原数字移除所有的数字，剩余为空就是0。
// 
// Related Topics 栈 贪心算法

#include "header.h"

namespace LeetCode402 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeKdigits(string num, int k) {
      return solution1(num, k);
    }

    // 对于相同长度的数字，最左边不同的数字决定了它们之间的大小
    // 故需要从左到右遍历，比较每两个元素，如果数字小于其左边的数字，则应该移除左边数字
    // 否则就不可能得到最小结果。 如 425，2比4小，应移除4，如果移除2的话，45就比25大了
    string solution1(string num, int k) {
      string ans;  // 使用string模拟栈
      for (char i : num) {
        while (k > 0 && !ans.empty() && i < ans.back()) {
          ans.pop_back();
          --k;  // 表示移除一个数字
        }
        // 跳过前置0
        if (ans.empty() && i == '0') continue;
        ans += i;
      }
      // 如果没有移除够 k 个字符
      while (!ans.empty() && k-- > 0) ans.pop_back();
      return ans.empty() ? "0" : ans;
    }

    // 贪心法，在保留有效长度的情况下，计算左边最小值保留作为高位值
    string solution2(string num, int k) {
      int n = num.size();
      if (k >= n) return "0";  // 移除了所有数字

      int len = n - k;  // 移除之后保留的字符串长度
      int i = 0;
      string ans;
      while (len > 0) {
        // 从 i 位置，到 n - len 位置，找出最小值，作为最高位
        int min_idx = i;
        int min_v = num[i];
        for (int j = i+1; j <= n - len; ++j) {
          if (num[j] < min_v) {
            min_idx = j;
            min_v = num[j];
          }
        }
        // 如果 ans 不为空，则直接拼接最小值
        // 如果为空，且 min_v 不为 0，则拼接
        if (!ans.empty() || min_v != '0') ans += min_v;
        i = min_idx + 1;  // 从最小值的右侧元素考虑起
        --len;  // 取了一个高位之后，考虑剩下元素，所以 len--
      }
      return ans.empty() ? "0" : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}