//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。 
//
// 
//
// 示例 1： 
//
// 输入：S = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
// 
//
// 
//
// 提示： 
//
// 
// S的长度在[1, 500]之间。 
// S只包含小写字母 'a' 到 'z' 。 
// 
// Related Topics 贪心算法 双指针 
// 👍 294 👎 0

#include "header.h"

namespace LeetCode763 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string S) {
      return solution1(S);
    }

    // 贪心法
    vector<int> solution1(string S) {
      vector<int> ans;
      int n = S.size();

      // 从最后开始，计算每个字符的最长距离
      int last_idx[26] = {0};  // 每个字符的最后一次出现位置
      for (int i = 0; i < n; ++i) {
        last_idx[S[i] - 'a'] = i;  // 记下 last_idx 的位置
      }

      // 开始分段
      int start = 0, end = 0;
      for (int i = 0; i < n; ++i) {
        end = max(end, last_idx[S[i] - 'a']);
        if (i == end) {
          ans.push_back(end - start + 1);
          start = end + 1;
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}