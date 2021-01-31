//有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是： 
//
// 
// 一块砖直接连接到网格的顶部，或者 
// 至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时 
// 
//
// 给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消
//失，然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。 
//
// 返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。 
//
// 注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
//输出：[2]
//解释：
//网格开始为：
//[[1,0,0,0]，
// [1,1,1,0]]
//消除 (1,0) 处加粗的砖块，得到网格：
//[[1,0,0,0]
// [0,1,1,0]]
//两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
//[[1,0,0,0],
// [0,0,0,0]]
//因此，结果为 [2] 。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
//输出：[0,0]
//解释：
//网格开始为：
//[[1,0,0,0],
// [1,1,0,0]]
//消除 (1,1) 处加粗的砖块，得到网格：
//[[1,0,0,0],
// [1,0,0,0]]
//剩下的砖都很稳定，所以不会掉落。网格保持不变：
//[[1,0,0,0], 
// [1,0,0,0]]
//接下来消除 (1,0) 处加粗的砖块，得到网格：
//[[1,0,0,0],
// [0,0,0,0]]
//剩下的砖块仍然是稳定的，所以不会有砖块掉落。
//因此，结果为 [0,0] 。 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// grid[i][j] 为 0 或 1 
// 1 <= hits.length <= 4 * 104 
// hits[i].length == 2 
// 0 <= xi <= m - 1 
// 0 <= yi <= n - 1 
// 所有 (xi, yi) 互不相同 
// 
// Related Topics 并查集 
// 👍 145 👎 0

#include "header.h"

namespace LeetCode803 {

//leetcode submit region begin(Prohibit modification and deletion)

class UnionFind{
 private:
  unordered_map<int,int> father;
  unordered_map<int,int> size_of_set;

 public:
  int find(int x){
    int root = x;

    while(father[root] != INT32_MAX){
      root = father[root];
    }
    // 路径压缩
    while(x != root){
      int original_father = father[x];
      father[x] = root;
      x = original_father;
    }

    return root;
  }

  int get_size_of_set(int x){
    // 获取所在连通块的大小
    return size_of_set[find(x)];
  }

  bool is_connected(int x,int y){
    return find(x) == find(y);
  }

  void merge(int x,int y){
    auto root_x = find(x);
    auto root_y = find(y);

    if(root_x != root_y){
      father[root_x] = root_y;
      // 更新根节点连通块的大小
      size_of_set[root_y] += size_of_set[root_x];
      size_of_set.erase(root_x);
    }
  }

  void add(int x){
    if(!father.count(x)){
      father[x] = INT32_MAX;
      size_of_set[x] = 1;
    }
  }
};

class Solution {
 private:
  int CEILING = -1;
  vector<pair<int,int>> DIRECTIONS = {{1,0},{-1,0},{0,1},{0,-1}};

 public:
  void initialize(UnionFind& uf,vector<vector<int>>& grid,const vector<vector<int>>& hits,const int& m,const int& n){
    /* 初始化 */
    // 添加天花板
    uf.add(CEILING);

    // 预先敲掉所有要敲掉的砖块
    for(int i = 0;i < hits.size();i++){
      grid[hits[i][0]][hits[i][1]]--;
    }

    // 连接，合并剩余的没有被敲掉的砖块
    for(int i = 0;i < m;i++)
      for(int j = 0;j < n;j++)
        if(grid[i][j] == 1){
          uf.add(i*n+j);
        }

    for(int i = 0;i < m;i++)
      for(int j = 0;j < n;j++)
        if(grid[i][j] == 1){
          merge_neighbors(uf,grid,i,j,m,n);
        }

    // 第0行的砖与天花板合并
    for(int j = 0;j < n;j++)
      if(grid[0][j] == 1)
        uf.merge(j,CEILING);
  }

  bool is_valid(const int& i,const int& j,vector<vector<int>>& grid,const int& m,const int& n){
    return 0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1;
  }

  void merge_neighbors(UnionFind& uf,vector<vector<int>>& grid,const int& i,const int& j,const int& m,const int& n){
    /* 与上下左右的砖块合并 */
    for(int k = 0;k < 4;k++){
      int new_x = i + DIRECTIONS[k].first;
      int new_y = j + DIRECTIONS[k].second;
      if(is_valid(new_x,new_y,grid,m,n)){
        uf.merge(new_x*n+new_y,i*n+j);
      }
    }
  }


  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    UnionFind uf;
    int m = grid.size(),n = grid[0].size();

    // 初始化
    initialize(uf,grid,hits,m,n);

    vector<int> res(hits.size(),0);

    for(int i = hits.size()-1;i >= 0;i--){
      int x = hits[i][0],y = hits[i][1];

      // 还原敲击
      if(++grid[x][y] != 1)
        continue;

      // 敲完后与天花板连接的数量
      int after_hit = uf.get_size_of_set(CEILING);

      // 填回砖块，与邻居合并
      uf.add(x*n+y);
      merge_neighbors(uf,grid,x,y,m,n);


      // 如果被敲掉的地方和天花板连接
      if(x == 0){
        uf.merge(y,CEILING);
      }

      if(uf.is_connected(x*n+y,CEILING)){
        // 敲之前和天花板连接的数量
        int before_hit = uf.get_size_of_set(CEILING);

        res[i] = before_hit - after_hit - 1;
      }
    }

    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}