//给出一个无重叠的 ，按照区间起始端点排序的区间列表。 
//
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。 
//
// 
//
// 示例 1： 
//
// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
//输出：[[1,5],[6,9]]
// 
//
// 示例 2： 
//
// 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//输出：[[1,2],[3,10],[12,16]]
//解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
// 
//
// 
//
// 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。 
// Related Topics 排序 数组 
// 👍 254 👎 0

#include "header.h"

namespace LeetCode57 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      return solution3(intervals, newInterval);
    }

    vector<vector<int>> solution1(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> ans;
      vector<int> insertInterval;
      bool inserted = false;
      for (auto e : intervals) {
        if (e[1] < newInterval[0] || inserted) {  // newInterval 在 e 的右边
          ans.push_back(e);
        } else if (e[0] > newInterval[1] && insertInterval.empty()) {  // newInterval 刚好在间隔内
          inserted = true;
          ans.push_back(newInterval);
          ans.push_back(e);
        } else {
          // e 和 newInterval 有重叠
          if (insertInterval.empty()) {
            insertInterval.push_back(min(e[0], newInterval[0]));
            insertInterval.push_back(max(e[1], newInterval[1]));
          } else if (e[0] > insertInterval[1]) {
            inserted = true;
            ans.push_back(insertInterval);
            ans.push_back(e);
          } else {
            insertInterval[1] = max(e[1], insertInterval[1]);  // 扩展间隔
          }
        }
      }
      if (!inserted) {
        if (!insertInterval.empty()) ans.push_back(insertInterval);
        else ans.push_back(newInterval);
      }
      return ans;
    }

    // 更简洁的解法
    vector<vector<int>> solution2(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int left = newInterval[0];
      int right = newInterval[1];
      bool placed = false;
      vector<vector<int>> ans;
      for (auto e : intervals) {
        if (e[0] > right) {
          // 和 newInterval 比较，左边界大于 newInterval 的右边
          // 说明 newInterval 在 e 的左边
          if (!placed) {
            ans.push_back({left, right});
            placed = true;
          }
          ans.push_back(e);
        } else if (e[1] < left) {
          // 和 newInterval 比较，右边界小于 newInterval 的左边
          // 说明 newInterval 在 e 的右边
          ans.push_back(e);
        } else {
          // 有交集
          left = min(left, e[0]);
          right = max(right, e[1]);
        }
      }
      if (!placed) ans.push_back({left, right});
      return ans;
    }

    // 二分法先找到要插入的位置
    vector<vector<int>> solution3(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int left = newInterval[0], right = newInterval[1];
      int p_left = 0, r = intervals.size();
      int middle;
      // 二分查找 left小于右边界的 第一个片段
      while (p_left < r) {
        middle = p_left + (r - p_left) / 2;
        if (intervals[middle][1] < left) p_left = middle + 1;
        else r = middle;
      }
      int p_right = p_left;
      r = intervals.size();
      // 二分查找 right小于左边界的 第一个片段
      while (p_right < r) {
        middle = p_right + (r - p_right) / 2;
        if (intervals[middle][0] > right) r = middle;
        else p_right = middle + 1;
      }
      // p_left 到 p_right-1 这一段就是要替换的片段
      vector<vector<int>> ans{intervals.begin(), intervals.begin() + p_left};
      if (p_left >= p_right) {
        ans.push_back(newInterval);
      } else {
        ans.push_back({min(left, intervals[p_left][0]), max(right, intervals[p_right-1][1])});
      }
      // 把剩下的一段补上
      for (auto v = intervals.begin() + p_right; v != intervals.end(); ++v) {
        ans.push_back(*v);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}