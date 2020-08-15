//给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。 
//
// 示例 1: 
//
// 输入: [[1,1],[2,2],[3,3]]
//输出: 3
//解释:
//^
//|
//|        o
//|     o
//|  o  
//+------------->
//0  1  2  3  4
// 
//
// 示例 2: 
//
// 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出: 4
//解释:
//^
//|
//|  o
//|     o        o
//|        o
//|  o        o
//+------------------->
//0  1  2  3  4  5  6 
// Related Topics 哈希表 数学

#include "header.h"

namespace LeetCode149 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      return solution1(points);
    }

    // O( N^2 )
    int solution1(vector<vector<int>>& points) {
      int n = points.size();
      if (n < 3) return n;

      function<int(int, int)> gcd = [&](int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
      };

      unordered_map<string, int> line;  // 记录一次点和其他所有点的斜率计数
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        int duplicate = 0;
        int curMax = 0;
        line.clear();
        for (int j = i + 1; j < n; ++j) {
          if (points[i] == points[j]) {
            ++duplicate;
            continue;
          }

          int diffX = points[j][0] - points[i][0];
          int diffY = points[j][1] - points[i][1];
          int tmp = gcd(diffX, diffY);  // 求两数的最大公约数
          // 得出斜率的最小分式
          string key = to_string(diffX / tmp) + "," + to_string(diffY / tmp);
          line[key]++;
          curMax = max(curMax, line[key]);
        }
        ans = max(ans, curMax + duplicate + 1);  // 需要将重复元素也计算上, 最后加上 i 点本身
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}