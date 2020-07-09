//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 
//
// 
//
// 示例: 
//
// MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.min();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.min();   --> 返回 -2.
// 
//
// 
//
// 提示： 
//
// 
// 各函数的调用总次数不超过 20000 次 
// 
//
// 
//
// 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/ 
// Related Topics 栈 设计

#include "header.h"

namespace LeetCode_30 {

//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
private:
  vector<int> stk;
  vector<int> minStk;
  int length = 0;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
      ++length;
      stk.push_back(x);
      if (minStk.empty())
        minStk.push_back(x);
      else
        minStk.push_back(::min(minStk.back(), x));
    }
    
    void pop() {
      if (length > 0) {
        stk.pop_back();
        minStk.pop_back();
        --length;
      }
    }
    
    int top() {  // 这里按C++的性质，错误的调用返回未知。。
      return stk.back();
    }
    
    int min() {
      return minStk.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
//leetcode submit region end(Prohibit modification and deletion)

}