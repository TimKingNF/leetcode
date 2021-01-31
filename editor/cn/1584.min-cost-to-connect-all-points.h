//给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。 
//
// 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 
//val 的绝对值。 
//
// 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//输出：20
//解释：
//
//我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
//注意到任意两个点之间只有唯一一条路径互相到达。
// 
//
// 示例 2： 
//
// 
//输入：points = [[3,12],[-2,5],[-4,1]]
//输出：18
// 
//
// 示例 3： 
//
// 
//输入：points = [[0,0],[1,1],[1,0],[-1,1]]
//输出：4
// 
//
// 示例 4： 
//
// 
//输入：points = [[-1000000,-1000000],[1000000,1000000]]
//输出：4000000
// 
//
// 示例 5： 
//
// 
//输入：points = [[0,0]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 1000 
// -106 <= xi, yi <= 106 
// 所有点 (xi, yi) 两两不同。 
// 
// Related Topics 并查集 
// 👍 69 👎 0

#include "header.h"

namespace LeetCode1584 {

//leetcode submit region begin(Prohibit modification and deletion)
class DisjointSetUnion {
 private:
  vector<int> f, rank;
  int n;

 public:
  DisjointSetUnion(int _n) {
    n = _n;
    rank.resize(n, 1);
    f.resize(n);
    for (int i = 0; i < n; i++) {
      f[i] = i;
    }
  }

  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
  }

  int unionSet(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) {
      return false;
    }
    if (rank[fx] < rank[fy]) {
      swap(fx, fy);
    }
    rank[fx] += rank[fy];
    f[fy] = fx;
    return true;
  }
};

class BIT {
 public:
  vector<int> tree, idRec;
  int n;

  BIT(int _n) {
    n = _n;
    tree.resize(n, INT32_MAX);
    idRec.resize(n, -1);
  }

  int lowbit(int k) {
    return k & (-k);
  }

  void update(int pos, int val, int id) {
    while (pos > 0) {
      if (tree[pos] > val) {
        tree[pos] = val;
        idRec[pos] = id;
      }
      pos -= lowbit(pos);
    }
  }

  int query(int pos) {
    int minval = INT32_MAX;
    int j = -1;
    while (pos < n) {
      if (minval > tree[pos]) {
        minval = tree[pos];
        j = idRec[pos];
      }
      pos += lowbit(pos);
    }
    return j;
  }
};

struct Edge {
  int len, x, y;
  Edge(int len, int x, int y) : len(len), x(x), y(y) {
  }
  bool operator<(const Edge& a) const {
    return len < a.len;
  }
};

struct Pos {
  int id, x, y;
  bool operator<(const Pos& a) const {
    return x == a.x ? y < a.y : x < a.x;
  }
};

class Solution {
 public:
  vector<Edge> edges;
  vector<Pos> pos;

  void build(int n) {
    sort(pos.begin(), pos.end());
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      a[i] = pos[i].y - pos[i].x;
      b[i] = pos[i].y - pos[i].x;
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int num = b.size();
    BIT bit(num + 1);
    for (int i = n - 1; i >= 0; i--) {
      int poss = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
      int j = bit.query(poss);
      if (j != -1) {
        int dis = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
        edges.emplace_back(dis, pos[i].id, pos[j].id);
      }
      bit.update(poss, pos[i].x + pos[i].y, i);
    }
  }

  void solve(vector<vector<int>>& points, int n) {
    pos.resize(n);
    for (int i = 0; i < n; i++) {
      pos[i].x = points[i][0];
      pos[i].y = points[i][1];
      pos[i].id = i;
    }
    build(n);
    for (int i = 0; i < n; i++) {
      swap(pos[i].x, pos[i].y);
    }
    build(n);
    for (int i = 0; i < n; i++) {
      pos[i].x = -pos[i].x;
    }
    build(n);
    for (int i = 0; i < n; i++) {
      swap(pos[i].x, pos[i].y);
    }
    build(n);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    solve(points, n);

    DisjointSetUnion dsu(n);
    sort(edges.begin(), edges.end());
    int ret = 0, num = 1;
    for (auto& [len, x, y] : edges) {
      if (dsu.unionSet(x, y)) {
        ret += len;
        num++;
        if (num == n) {
          break;
        }
      }
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}