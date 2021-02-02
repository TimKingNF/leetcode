//在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只
//能放在更大的盘子上面)。移动圆盘时受到以下限制: 
//(1) 每次只能移动一个盘子; 
//(2) 盘子只能从柱子顶端滑出移到下一根柱子; 
//(3) 盘子只能叠在比它大的盘子上。 
//
// 请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。 
//
// 你需要原地修改栈。 
//
// 示例1: 
//
//  输入：A = [2, 1, 0], B = [], C = []
// 输出：C = [2, 1, 0]
// 
//
// 示例2: 
//
//  输入：A = [1, 0], B = [], C = []
// 输出：C = [1, 0]
// 
//
// 提示: 
//
// 
// A中盘子的数目不大于14个。 
// 
// Related Topics 递归 
// 👍 75 👎 0

#include "header.h"

namespace LeetCode_08_06 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
      return solution2(A, B, C);
    }

    // 使用递归求解
    void solution1(vector<int>& A, vector<int>& B, vector<int>& C) {
      int n = A.size();
      if (n < 1) return;
      solution1_process(n, A, B, C, 0, 2);
    }

    // n 表示移动几层汉诺塔，from to 表示从 from 移动所有的盘子到 to 上
    int solution1_process(int n, vector<int>& A, vector<int>& B, vector<int>& C,
                          int from, int to) {
      if (from == to) return 0;  // 无需操作，返回步数0

      int x;
      auto& fromItem = from == 0 ? A : (from == 1 ? B : C);
      auto& toItem = to == 0 ? A : (to == 1 ? B : C);
      if (n == 1) {  // 说明只有一个盘子
        if (from == 1 || to == 1) {  // 说明只有一步操作
          x = fromItem.back();
          fromItem.pop_back();
          toItem.push_back(x);
          // cout << "Move " << x << " from " << from << " to " << to << endl;
          return 1;
        } else {  // 有两步操作
          x = fromItem.back();
          fromItem.pop_back();
          // cout << "Move " << x << " from " << from << " to 1" << endl;
          // 省略移动到 B
          // B.push_back(x);
          // x = B.back();
          // B.pop_back();
          // cout << "Move " << x << " from 1 to " << to << endl;
          toItem.push_back(x);
          return 2;
        }
      }
      if (from == 1 || to == 1) {  // from 和 to 其中有一个为 B
        // 其中有一个为 A，则借用 C
        int another = (from == 0 || to == 0) ? 2 : 0;
        // 先把 n-1 层移动到另一个去
        int part1Steps = solution1_process(n-1, A, B, C, from, another);
        int part2Steps = 1;  // 将 from 处的最后一层（ n ）移动到 to 上
        x = fromItem.back();
        fromItem.pop_back();
        toItem.push_back(x);
        // cout << "Move " << x << " from " << from << " to " << to << endl;
        // 最后将 n-1 层从 another 移回到 to 上
        int part3Steps = solution1_process(n-1, A, B, C, another, to);
        return part1Steps + part2Steps + part3Steps;
      } else {
        // from to 必不相邻, 先求解将 n-1 级汉诺塔由 from 移向 to
        int part1Steps = solution1_process(n-1, A, B, C, from, to);
        // 将第 n 级从 from 移动到 B
        int part2Steps = 1;
        x = fromItem.back();
        fromItem.pop_back();
        B.push_back(x);
        // cout << "Move " << x << " from " << from << " to 1" << endl;
        // 再将 n-1 级由 to 移动回 from
        int part3Steps = solution1_process(n-1, A, B, C, to, from);
        // 将第 n 级从 B 移动到 to
        int part4Steps = 1;
        x = B.back();
        B.pop_back();
        toItem.push_back(x);
        // cout << "Move " << x << " from 1 to " << to << endl;
        // 最后将 n-1 级由 from 移动到 to
        int part5Steps = solution1_process(n-1, A, B, C, from, to);
        return part1Steps + part2Steps + part3Steps + part4Steps + part5Steps;
      }
    }

    // 在汉诺塔的移动过程中，只可能有这 4 种情况
    enum Action {
      No, L2M, M2L, M2R, R2M
    };

    // 使用栈求解, 使用 vector 模拟栈
    void solution2(vector<int>& A, vector<int>& B, vector<int>& C) {
      Action action = No;  // 上一次执行的动作
      auto solution2_process = [&](Action noAct, Action nowAct, int from, int to) {
        // noAct 表示和 nowAct 逆序的动作，即如果上一次执行了 L2M, 则本次没有必要执行 M2L
        // 且需要满足，本次动作，fromStack 的栈顶元素 < toStack 栈顶元素, 才可以移动
        auto& fromStack = from == 0 ? A : (from == 1 ? B : C);
        auto& toStack = to == 0 ? A : (to == 1 ? B : C);
        if (action != noAct && !fromStack.empty() &&
            (toStack.empty() || fromStack.back() < toStack.back())) {
          // cout << "Move " << fromStack.back() << " from " << from << " to " << to << endl;
          toStack.push_back(fromStack.back());
          fromStack.pop_back();
          action = nowAct;
          return 1;
        }
        return 0;
      };

      int step = 0;
      int n = A.size();
      while (C.size() != n) {
        // 考虑4种情况，只会有一个满足
        step += solution2_process(M2L, L2M, 0, 1);
        step += solution2_process(L2M, M2L, 1, 0);
        step += solution2_process(R2M, M2R, 1, 2);
        step += solution2_process(M2R, R2M, 2, 1);
      }
      // cout << "Need " << step << endl;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}