//请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(
//1)。 示例： MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0);
// minStack.push(-3); minStack.getMin();   --> 返回 -3. minStack.pop(); minStack.top
//();      --> 返回 0. minStack.getMin();   --> 返回 -2. Related Topics 栈

#include "header.h"

namespace LeetCode_03_02 {

//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
private:
    vector<int> min_stk;
    vector<int> stk;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
      stk.push_back(x);
      if (min_stk.empty() || min_stk.back() >= x) min_stk.push_back(x);
    }
    
    void pop() {
      if (stk.size() == 0) return;
      if (stk.back() == min_stk.back()) min_stk.pop_back();
      stk.pop_back();
    }
    
    int top() {
      return stk.back();
    }
    
    int getMin() {
      return min_stk.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)

}