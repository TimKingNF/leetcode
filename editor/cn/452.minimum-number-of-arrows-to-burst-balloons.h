//在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横
//坐标就足够了。开始坐标总是小于结束坐标。 
//
// 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足 xsta
//rt ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的
//最小数量。 
//
// 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。 
// 
//
// 示例 1： 
//
// 
//输入：points = [[10,16],[2,8],[1,6],[7,12]]
//输出：2
//解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球 
//
// 示例 2： 
//
// 
//输入：points = [[1,2],[3,4],[5,6],[7,8]]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：points = [[1,2],[2,3],[3,4],[4,5]]
//输出：2
// 
//
// 示例 4： 
//
// 
//输入：points = [[1,2]]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：points = [[2,3],[2,3]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 0 <= points.length <= 104 
// points[i].length == 2 
// -231 <= xstart < xend <= 231 - 1 
// 
// Related Topics 贪心算法 排序 
// 👍 236 👎 0

#include "header.h"

namespace LeetCode452 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      return solution2(points);
    }

    // 贪心策略
    int solution1(vector<vector<int>>& points) {
      if (points.empty()) return 0;
      int n = points.size();
      sort(points.begin(), points.end());

      int ans = 1;
      int end = points[0][1];
      int next_start, next_end;
      for (int i = 1; i < n; ++i) {
        next_start = points[i][0];
        next_end = points[i][1];

        if (end < next_start) {  // end 位置无法射爆下一个气球
          ans++;  // 需要射出下一箭
          end = next_end;
        } else {
          end = min(end, next_end);
        }
      }
      return ans;
    }

    // 对 solution1 简化一下
    int solution2(vector<vector<int>>& points) {
      if (points.empty()) return 0;
      // 按右边界升序排序
      sort(points.begin(), points.end(), [](const vector<int>& l, const vector<int>& r){
        return l[1] < r[1];
      });
      int pos = points[0][1];
      int ans = 1;
      for (const auto& v: points) {
        if (v[0] > pos) {
          pos = v[1];
          ++ans;
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}