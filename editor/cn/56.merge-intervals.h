//给出一个区间的集合，请合并所有重叠的区间。 
//
// 示例 1: 
//
// 输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2: 
//
// 输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
// Related Topics 排序 数组

#include "header.h"

namespace LeetCode56 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      return solution2(intervals);
    }

    static bool cmp(vector<int>& first, vector<int>& second) {
      return first[0] < second[0];
    }

    vector<vector<int>> solution1(vector<vector<int>>& intervals) {
      if (intervals.empty()) return {};
      // 按元素首个进行排序
      sort(intervals.begin(), intervals.end(), cmp);
      int pre_first = intervals[0][0], pre_second = intervals[0][1];

      vector<vector<int>> ans;
      vector<int> line;
      for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= pre_first && intervals[i][0] <= pre_second)
          pre_second = max(intervals[i][1], pre_second);
        else if (intervals[i][0] < pre_first) {
          pre_first = intervals[i][0];
          pre_second = max(intervals[i][1], pre_second);
        } else if (intervals[i][0] > pre_second) {
          // 发生截断
          line = {pre_first, pre_second};
          ans.push_back(line);
          pre_first = intervals[i][0];
          pre_second = intervals[i][1];
        }
      }
      line = {pre_first, pre_second};
      ans.push_back(line);  // 插入最后一个
      return ans;
    }

    vector<vector<int>> solution2(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());  // 默认直接取 vector 的第一个元素
      vector<vector<int>> ans;
      int last;
      for (auto interval : intervals) {
        last = ans.size()-1;
        if (ans.empty() || ans[last][1] < interval[0]) {
          ans.push_back(interval);
        } else {
          ans[last][1] = max(ans[last][1], interval[1]);
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}