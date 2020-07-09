//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都
//是O(1)。 
//
// 若队列为空，pop_front 和 max_value 需要返回 -1 
//
// 示例 1： 
//
// 输入: 
//["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
//[[],[1],[2],[],[],[]]
//输出: [null,null,null,2,1,2]
// 
//
// 示例 2： 
//
// 输入: 
//["MaxQueue","pop_front","max_value"]
//[[],[],[]]
//输出: [null,-1,-1]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= push_back,pop_front,max_value的总操作数 <= 10000 
// 1 <= value <= 10^5 
// 
// Related Topics 栈 Sliding Window

#include "header.h"

namespace LeetCode_59_II {

//leetcode submit region begin(Prohibit modification and deletion)
class MaxQueue {
private:
  deque<int> data;
  deque<int> maximums;
public:
    MaxQueue() {

    }
    
    int max_value() {
      if (data.empty()) return -1;
      return maximums.back();
    }
    
    void push_back(int value) {
      data.push_back(value);
      while (!maximums.empty() && value > maximums.front())  // 等于不弹出，防止出现两个一样大的元素
        maximums.pop_front();
      maximums.push_front(value);
    }
    
    int pop_front() {
      if (data.empty()) return -1;
      int v = data.front();
      if (v == maximums.back())  // 如果弹出的元素等于最大元素的话，则弹出最大元素
        maximums.pop_back();
      data.pop_front();
      return v;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
//leetcode submit region end(Prohibit modification and deletion)

}