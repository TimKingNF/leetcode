//给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺
//序）。 
//
// 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。 
//
// 示例: 
//
// 
//输入:
//[[0,0],[1,0],[2,0]]
//
//输出:
//2
//
//解释:
//两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
// 
// Related Topics 哈希表

#include "header.h"

namespace LeetCode447 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
      return solution1(points);
    }

    int solution1(vector<vector<int>>& points) {
      int n = points.size();
      // key 是两点之间的距离，value 是记录组的点
      unordered_map<int, vector<pair<int, int>>> dict;
      int ans = 0;
      // 因为回旋镖相同座标位置不同也算不同，所以只需计算一半矩阵即可， 而且需要去掉边界线
      for (int i = 0; i <= n - 2; ++i) {
        for (int j = i + 1; j <= n - 1; ++j) {
          int x_diff = points[i][0] - points[j][0];
          int y_diff = points[i][1] - points[j][1];
          int distance = x_diff * x_diff + y_diff * y_diff;
          if (dict.count(distance)) {
            for (auto v : dict[distance]) {
              // 满足两组点之间有一个点相同
              if (v.first == i || v.second == i || v.first == j || v.second == j) ++ans;
            }
            dict[distance].push_back({i, j});
          } else {
            dict[distance] = {{i, j}};
          }
        }
      }
      return ans * 2;  // 上图的矩阵只计算了一半，所以需要 * 2
    }

  };
//leetcode submit region end(Prohibit modification and deletion)

}