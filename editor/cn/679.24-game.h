//你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。 
//
// 示例 1: 
//
// 输入: [4, 1, 8, 7]
//输出: True
//解释: (8-4) * (7-1) = 24
// 
//
// 示例 2: 
//
// 输入: [1, 2, 1, 2]
//输出: False
// 
//
// 注意: 
//
// 
// 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。 
// 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允
//许的。 
// 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。 
// 
// Related Topics 深度优先搜索

#include "header.h"

namespace LeetCode679 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
      return solution1(nums);
    }

   private:
    float eps = 1e-6;

    // dfs
    bool solution1(vector<int>& nums) {
      deque<float> q;
      for (int x : nums) q.push_back(x);
      return dfs(q);
    }

    bool dfs(deque<float>& q) {
      const int n = q.size();
      if (n == 1) return abs(q.front() - 24) < eps;  // 只剩最后一个数了，和24比较精度

      // 遍历取出两个元素进行计算
      for (int i = 0; i < n; ++i) {
        float a = q.front(); q.pop_front();
        for (int j = 1; j < n; ++j) {
          float b = q.front(); q.pop_front();
          if (next(q, a + b) ||
              next(q, a - b) ||
              next(q, a * b) ||
              (b ? next(q, a / b) : 0)) {
            return true;
          }
          q.push_back(b);  // 计算完一轮之后将 b 再放回去，恢复到 q 仍有 4 个元素，只是排列不同
        }
        q.push_back(a);  // 同上
      }
      return false;
    }

    bool next(deque<float>& q, float v) {
      q.push_back(v);  // 将 v 加入 q 中进行下一轮运算
      bool b = dfs(q);
      q.pop_back();  // 恢复状态
      return b;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}