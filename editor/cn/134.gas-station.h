//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。 
//
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。 
//
// 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。 
//
// 说明: 
//
// 
// 如果题目有解，该答案即为唯一答案。 
// 输入数组均为非空数组，且长度相同。 
// 输入数组中的元素均为非负数。 
// 
//
// 示例 1: 
//
// 输入: 
//gas  = [1,2,3,4,5]
//cost = [3,4,5,1,2]
//
//输出: 3
//
//解释:
//从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//因此，3 可为起始索引。 
//
// 示例 2: 
//
// 输入: 
//gas  = [2,3,4]
//cost = [3,4,3]
//
//输出: -1
//
//解释:
//你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
//我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
//开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
//开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
//你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
//因此，无论怎样，你都不可能绕环路行驶一周。 
// Related Topics 贪心算法 
// 👍 479 👎 0

#include "header.h"

namespace LeetCode134 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      return solution2(gas, cost);
    }

    // 贪心法
    int solution1(vector<int>& gas, vector<int>& cost) {
      // 首先检查是否有解, 计算耗油的差值
      int n = gas.size();
      cost[n-1] = gas[n-1] - cost[n-1];
      int max_v = cost[n-1], max_idx = n-1;
      for (int i = n-2; i >= 0; --i) {
        cost[i] = gas[i] - cost[i] + cost[i+1];
        if (cost[i] > max_v) {
          max_v = cost[i];
          max_idx = i;
        }
      }
      if (cost[0] < 0) return -1;  // 总耗油剩余量 < 0, 说明无解

      // 已知有解，cost 从右往左遍历，取最大值的下标
      return max_idx;
    }

    // 数学证明：从 x 出发，如无法到达 y，则 x,y 之间任何一个加油站出发，都不能到达 y
    int solution2(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      int i = 0;
      while (i < n) {
        int sum_of_gas = 0, sum_of_cost = 0;
        int cnt = 0;  // 记录能走过多少个站点
        while (cnt < n) {
          int j = (i + cnt) % n;  // 因为是环形的
          sum_of_gas += gas[j];
          sum_of_cost += cost[j];
          if (sum_of_cost > sum_of_gas) {  // 说明到了这个站点发现油不够了
            break;
          }
          ++cnt;
        }
        if (cnt == n) return i;  // 能够环绕一圈，说明i满足结果
        i = i + cnt + 1;  // 从不能到的这个站的下一个站出发
      }
      return -1;  // 所有加油站都不能作为起点
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}