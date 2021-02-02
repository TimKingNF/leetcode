//栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：pu
//sh、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。 
//
// 示例1: 
//
//  输入：
//["SortedStack", "push", "push", "peek", "pop", "peek"]
//[[], [1], [2], [], [], []]
// 输出：
//[null,null,null,1,null,2]
// 
//
// 示例2: 
//
//  输入： 
//["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
//[[], [], [], [1], [], []]
// 输出：
//[null,null,null,null,null,true]
// 
//
// 说明: 
//
// 
// 栈中的元素数目在[0, 5000]范围内。 
// 
// Related Topics 设计 
// 👍 30 👎 0

#include "header.h"

namespace LeetCode_03_05 {

//leetcode submit region begin(Prohibit modification and deletion)
class SortedStack {
 private:
  // 其中 left 记录从栈底到栈顶递减
  // right 记录从栈底到栈顶递增, 保证 right 的栈底元素是最小值
  stack<int> left, right;
public:
    SortedStack() {

    }

    // 接受一个栈，将其排序
    SortedStack(stack<int>& stk) {
      while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        // 保证 cur 在 right 中在最小的位置下
        while (!right.empty() && cur < right.top()) {
          stk.push(right.top());
          right.pop();
        }
        right.push(cur);
      }
      // 此时 stk 为空， right 从栈顶到栈底递减，搬运回 left
      while (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
    }
    
    void push(int val) {
      while (!right.empty() && right.top() > val) {
        left.push(right.top());
        right.pop();
      }
      while (!left.empty() && left.top() < val) {
        right.push(left.top());
        left.pop();
      }
      left.push(val);
    }
    
    void pop() {
      while (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
      if (!left.empty()) left.pop();
    }
    
    int peek() {
      while (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
      return !left.empty() ? left.top() : -1;
    }
    
    bool isEmpty() {
      return left.empty() && right.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
//leetcode submit region end(Prohibit modification and deletion)

}