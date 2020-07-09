//给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时
//，返回 true；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
//输出：true
//解释：我们可以按以下顺序执行：
//push(1), push(2), push(3), push(4), pop() -> 4,
//push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// 
//
// 示例 2： 
//
// 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
//输出：false
//解释：1 不能在 2 之前弹出。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= pushed.length == popped.length <= 1000 
// 0 <= pushed[i], popped[i] < 1000 
// pushed 是 popped 的排列。 
// 
// Related Topics 栈

#include "header.h"

namespace LeetCode946 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      return solution1(pushed, popped);
    }

    bool solution1(vector<int>& pushed, vector<int>& popped) {
      if (pushed.size() != popped.size()) return false;
      int i = 0;
      stack<int> stk;
      for (auto v : popped) {
        if (!stk.empty() && stk.top() == v) {
          stk.pop();
          continue;
        }
        while (i < pushed.size() && pushed[i] != v) {
          stk.push(pushed[i++]);
        }
        ++i;  // 跳过 pushed[i] == v 的元素
      }
      return stk.empty();
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}