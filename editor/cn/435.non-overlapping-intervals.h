//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。 
//
// 注意: 
//
// 
// 可以认为区间的终点总是大于它的起点。 
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。 
// 
//
// 示例 1: 
//
// 
//输入: [ [1,2], [2,3], [3,4], [1,3] ]
//
//输出: 1
//
//解释: 移除 [1,3] 后，剩下的区间没有重叠。
// 
//
// 示例 2: 
//
// 
//输入: [ [1,2], [1,2], [1,2] ]
//
//输出: 2
//
//解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
// 
//
// 示例 3: 
//
// 
//输入: [ [1,2], [2,3] ]
//
//输出: 0
//
//解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
// 
// Related Topics 贪心算法 
// 👍 296 👎 0

#include "header.h"

namespace LeetCode435 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      return solution1(intervals);
    }

    // 贪心
    // O（ N * logN ）, O( logN )
    int solution1(vector<vector<int>>& intervals) {
      int n = intervals.size();
      if (n <= 1) return 0;
      // 按右端点大小进行排序
      sort(intervals.begin(), intervals.end(), [](const auto& first, const auto& second){
        return first[1] < second[1];
      });
      int retain = 1;  // 最终保留下的区间数
      int right = intervals[0][1];
      for (int i = 1; i < n; ++i) {
        if (intervals[i][0] >= right) {
          ++retain;
          right = intervals[i][1];
        }
      }
      return n - retain;
    }

    // dp
    int solution2(vector<vector<int>>& intervals) {
      if (intervals.empty()) return 0;
      sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
        return u[0] < v[0];
      });

      int n = intervals.size();
      vector<int> f(n, 1);
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (intervals[j][1] <= intervals[i][0]) {
            f[i] = max(f[i], f[j] + 1);
          }
        }
      }
      return n - *max_element(f.begin(), f.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}