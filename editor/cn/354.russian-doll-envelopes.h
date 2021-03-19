//给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如
//同俄罗斯套娃一样。 
//
// 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。 
//
// 说明: 
//不允许旋转信封。 
//
// 示例: 
//
// 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//输出: 3 
//解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
// 
// Related Topics 二分查找 动态规划 
// 👍 362 👎 0

#include "header.h"

namespace LeetCode354 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      return solution2(envelopes);
    }

    int solution1(vector<vector<int>>& envelopes) {
      if (envelopes.empty()) return 0;
      int n = envelopes.size();

      // 固定一个维度, 让 w 固定从小到大，h 固定从大到小
      // 这样就保证了。对于每个 w， 我们最多只能选择一个信封
      sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
      });

      int ans = 0;
      int dp[n];
      fill(dp, dp+n, 1);

      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (envelopes[j][1] < envelopes[i][1]) {
            dp[i] = max(dp[i], dp[j]+1);
            ans = max(ans, dp[i]);
          }
        }
      }
      return ans;
    }

    int solution2(vector<vector<int>>& envelopes) {
      if (envelopes.empty()) return 0;
      int n = envelopes.size();
      sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
      });

      vector<int> dp = {envelopes[0][1]};
      for (int i = 1; i < n; ++i) {
        if (int num = envelopes[i][1]; num > dp.back()) {  // 可以扩充为更大的字符串
          dp.push_back(num);
        } else {
          // 找到小于num 的最大值, 该值替换为 num，表示更新能插入的最大信封
          // 保证有序的计算有更大的余地
          auto it = lower_bound(dp.begin(), dp.end(), num);
          *it = num;
        }
      }
      return dp.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}