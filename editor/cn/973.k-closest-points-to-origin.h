//我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。 
//
// （这里，平面上两点之间的距离是欧几里德距离。） 
//
// 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。 
//
// 
//
// 示例 1： 
//
// 输入：points = [[1,3],[-2,2]], K = 1
//输出：[[-2,2]]
//解释： 
//(1, 3) 和原点之间的距离为 sqrt(10)，
//(-2, 2) 和原点之间的距离为 sqrt(8)，
//由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
//我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
// 
//
// 示例 2： 
//
// 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
//输出：[[3,3],[-2,4]]
//（答案 [[-2,4],[3,3]] 也会被接受。）
// 
//
// 
//
// 提示： 
//
// 
// 1 <= K <= points.length <= 10000 
// -10000 < points[i][0] < 10000 
// -10000 < points[i][1] < 10000 
// 
// Related Topics 堆 排序 分治算法 
// 👍 144 👎 0

#include "header.h"

namespace LeetCode973 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      return solution2(points, K);
    }

    using pair_t = pair<int, int>;
    struct cmp {
      bool operator ()(pair_t& first, pair_t& second) {
        return first.first < second.first;  // vector 中从小到大
      }
    };

    // 堆排
    // O( nlogK ), O( K )
    vector<vector<int>> solution1(vector<vector<int>>& points, int K) {
      priority_queue<pair_t, vector<pair_t>, cmp> pq;  // 大顶堆, cmp 是 less，刚好相反
      for (int i = 0; i < points.size(); ++i) {
        pair_t v = {getDistanceSquareToOrigin(points[i]), i};
        if (pq.size() >= K) {
          if (v.first < pq.top().first) {
            pq.pop();
            pq.push(v);
          }
        } else {
          pq.push(v);
        }
      }
      vector<vector<int>> ans;
      while (!pq.empty()) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
      }
      return ans;
    }

    int getDistanceSquareToOrigin(vector<int>& first) {
      return first[0] * first[0] + first[1] * first[1];
    }

    // 快排
    vector<vector<int>> solution2(vector<vector<int>>& points, int K) {
       quick_sort(points, K, 0, points.size()-1);
       return vector<vector<int>>{points.begin(), points.begin()+K};
    }

    int partition(vector<vector<int>>& points, int l, int r) {
      int sp = getDistanceSquareToOrigin(points[r]);
      int less = l;
      for (int i = l; i < r; ++i) {
        if (getDistanceSquareToOrigin(points[i]) <= sp) {
          swap(points[i], points[less]);
          ++less;
        }
      }
      swap(points[less], points[r]);
      return less;  // 返回区分两边值的临界点
    }

    void quick_sort(vector<vector<int>>& points, int K, int l, int r) {
      if (l >= 0 &&l < r) {
        auto p = partition(points, l, r);
        if ((p - l + 1) == K) return;
        else if ((p - l + 1) > K) {  // 说明 p 点在 K 值右侧
          quick_sort(points, K, l, p-1);  // 缩小范围
        } else {
          quick_sort(points, K - (p-l+1), p+1, r);
        }
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}