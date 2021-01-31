//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连
//。 
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
// 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 449 👎 0

#include "header.h"

namespace LeetCode547 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      return solution1(isConnected);
    }

    // dfs
    int solution1(vector<vector<int>>& isConnected) {
      int n = isConnected.size();  // 总共有 n 个城市
      int ans = 0;

      function<void(int)> dfs = [&](int idx){
        isConnected[idx][idx] = 0;
        for (int i = 0; i < n; ++i) {
          if (isConnected[idx][i] == 1) {  // idx 和 i 两个城市联通
            isConnected[idx][i] = isConnected[i][idx] = 0;  // 清除掉两边的联通记录
            dfs(i);
          }
        }
      };

      for (int i = 0; i < n; ++i) {  // 第 i 个城市
        for (int j = 0; j < n; ++j) {
          if (isConnected[i][j] == 1) {  // 说明该城市与其他城市联通
            ans++;
            dfs(i);
            break;  // 后续的城市都不用再看
          }
        }
      }
      return ans;
    }

    // TODO: 并查集
};
//leetcode submit region end(Prohibit modification and deletion)

}