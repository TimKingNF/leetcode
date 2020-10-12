//在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。 
//
// 输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边
//不属于树中已存在的边。 
//
// 结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v 的一个父节点。 
//
//
// 返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。 
//
// 示例 1: 
//
// 输入: [[1,2], [1,3], [2,3]]
//输出: [2,3]
//解释: 给定的有向图如下:
//  1
// / \
//v   v
//2-->3
// 
//
// 示例 2: 
//
// 输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
//输出: [4,1]
//解释: 给定的有向图如下:
//5 <- 1 -> 2
//     ^    |
//     |    v
//     4 <- 3
// 
//
// 注意: 
//
// 
// 二维数组大小的在3到1000范围内。 
// 二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。 
// 
// Related Topics 树 深度优先搜索 并查集 图

#include "header.h"

namespace LeetCode685 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
      return solution1(edges);
    }

    // 无法构成数存在以下两种情况
    // 1. 同一个节点有两个父节点
    // 2. 在图中存在有向环
    vector<int> solution1(vector<vector<int>>& edges) {
      int n = edges.size();
      UnionFind uf = UnionFind(n + 1);
      auto rp = vector<int>(n + 1);  // 用于记录节点的代表节点
      for (int i = 0; i <= n; ++i) rp[i] = i;

      int conflict = -1;
      int cycle = -1;
      for (int i = 0; i < n; ++i) {
        if (rp[edges[i][1]] != edges[i][1]) {  // 说明同一个节点有两个父节点
          conflict = i;  // 记录下冲突的边
        } else {
          rp[edges[i][1]] = edges[i][0];  // 记录子节点的父节点
          // 如果两个节点之间的最低一级可访问节点相同的话，说明存在环
          if (uf.find(edges[i][0]) == uf.find(edges[i][1])) {
            cycle = i;
          } else {
            uf.merge(edges[i][0], edges[i][1]);  // 将边信息记录到并查集中
          }
        }
      }
      if (conflict < 0) {
        return edges[cycle];  // 没有同一个节点有两个父节点的边，则一定存在环
      } else {
        auto conflictEdge = edges[conflict];
        // 导致冲突的边，一条是 conflictEdge, 另一条是正常的 {rp[conflictEdge[1]], conflictEdge[1]}
        if (cycle >= 0) {
          // 如果有导致环存在的边，则 conflictEdge 不可能是该边，因为在上面的代码中已经被记为冲突边了
          return {rp[conflictEdge[1]], conflictEdge[1]};  // 如果存在环，返回导致出现环且是冲突的该边
        } else {
          return conflictEdge;  // 没有环，移除该冲突边即可
        }
      }
    }

private:
  struct UnionFind {
    vector <int> ancestor;

    UnionFind(int n) {
      ancestor.resize(n);
      for (int i = 0; i < n; ++i) {
        ancestor[i] = i;
      }
    }

    // 找到节点对应的最低一级节点
    int find(int index) {
      return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v) {
      ancestor[find(u)] = find(v);
    }
  };
};
//leetcode submit region end(Prohibit modification and deletion)

}