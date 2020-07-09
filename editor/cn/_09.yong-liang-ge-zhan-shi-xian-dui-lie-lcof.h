//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的
//功能。(若队列中没有元素，deleteHead 操作返回 -1 ) 
//
// 
//
// 示例 1： 
//
// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
// 
//
// 示例 2： 
//
// 输入：
//["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
//[[],[],[5],[2],[],[]]
//输出：[null,-1,null,null,5,2]
// 
//
// 提示： 
//
// 
// 1 <= values <= 10000 
// 最多会对 appendTail、deleteHead 进行 10000 次调用 
// 
// Related Topics 栈 设计

#include "header.h"

namespace LeetCode_09 {

//leetcode submit region begin(Prohibit modification and deletion)
class CQueue {
public:
    CQueue() {}
    
    void appendTail(int value) {
      stack1.push(value);
    }
    
    int deleteHead() {
      if (stack2.empty()) {
        // 将stack1 的元素都压入到 stack2 中
        while (!stack1.empty()) {
          stack2.push(stack1.top());
          stack1.pop();
        }
      }

      // 此时 stack2 还是 empty 说明队列中没有元素
      if (stack2.empty()) return -1;
      int res = stack2.top();
      stack2.pop();
      return res;
    }

private:
  stack<int> stack1;
  stack<int> stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
//leetcode submit region end(Prohibit modification and deletion)

}