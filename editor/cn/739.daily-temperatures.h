//请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 
//
// 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2
//, 1, 1, 0, 0]。 
//
// 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。 
// Related Topics 栈 哈希表

#include "header.h"

namespace LeetCode739 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      return solution1(T);
    }

    vector<int> solution1(vector<int>& T) {
      if (T.empty()) return {};
      int n = T.size();
      vector<int> ans(n, 0);
      stack<pair<int, int>> stk;  // 第一个数记数值，第二个记下标
      stk.push({T[0], 0});

      for (int i = 1; i < n; ++i) {
        if (T[i] <= stk.top().first) stk.push({T[i], i});
        else {
          while (!stk.empty() && T[i] > stk.top().first) {
            ans[stk.top().second] = i - stk.top().second;  // 需要等待的天数
            stk.pop();
          }
          stk.push({T[i], i});
        }
      }
      // stk 剩余的元素都为0
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}