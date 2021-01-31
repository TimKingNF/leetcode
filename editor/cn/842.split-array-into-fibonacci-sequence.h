//给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。 
//
// 形式上，斐波那契式序列是一个非负整数列表 F，且满足： 
//
// 
// 0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）； 
// F.length >= 3； 
// 对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。 
// 
//
// 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。 
//
// 返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。 
//
// 
//
// 示例 1： 
//
// 输入："123456579"
//输出：[123,456,579]
// 
//
// 示例 2： 
//
// 输入: "11235813"
//输出: [1,1,2,3,5,8,13]
// 
//
// 示例 3： 
//
// 输入: "112358130"
//输出: []
//解释: 这项任务无法完成。
// 
//
// 示例 4： 
//
// 输入："0123"
//输出：[]
//解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
// 
//
// 示例 5： 
//
// 输入: "1101111"
//输出: [110, 1, 111]
//解释: 输出 [11,0,11,11] 也同样被接受。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= S.length <= 200 
// 字符串 S 中只含有数字。 
// 
// Related Topics 贪心算法 字符串 回溯算法 
// 👍 141 👎 0

#include "header.h"

namespace LeetCode842 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
      return solution1(S);
    }

    // TODO: 回溯法
    vector<int> solution1(string& S) {
      vector<int> ans;
      backtrack(ans, S, S.size(), 0, 0, 0);
      return ans;
    }

    // idx 序列以外的下一个数下标
    bool backtrack(vector<int>& ans, string& S, int n, int idx, long long sum, int prev) {
      if (idx == n) {
        return ans.size() >= 3;
      }
      long long cur = 0;
      for (int i = idx; i < n; ++i) {
        if (i > idx && S[idx] == '0') break;  // 跳过0开头的数
        cur = cur * 10 + S[i] - '0';
        if (cur > INT32_MAX) break;  // 每一个数都没有超过 2^31-1
        if (ans.size() >= 2) {
          if (cur < sum) continue;
          else if (cur > sum) break;
        }
        ans.push_back(cur);
        if (backtrack(ans, S, n, i + 1, prev + cur, cur)) return true;
        ans.pop_back();
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}