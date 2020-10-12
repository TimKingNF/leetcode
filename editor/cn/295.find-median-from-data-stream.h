//中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。 
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例： 
//
// addNum(1)
//addNum(2)
//findMedian() -> 1.5
//addNum(3) 
//findMedian() -> 2 
//
// 进阶: 
//
// 
// 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？ 
// 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？ 
// 
// Related Topics 堆 设计

#include "header.h"

namespace LeetCode295 {

//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
 private:
  // 数据流中排序，形成有序列表，再取中位数
  priority_queue<int, vector<int>, less<>> left;  // 最大堆, 存放数据流左边的元素
  priority_queue<int, vector<int>, greater<>> right;  // 最小堆, 存放数据流右边的元素
 public:
  /** initialize your data structure here. */
  MedianFinder() {

  }

  void addNum(int num) {
    if (left.size() == right.size()) {
      // 当前总元素是偶数
      // 要保证right 的值都大于 left 的值
      // 比较当前元素，如果比 left 最大值要小，则从 left 中取出 max 放入 right 中
      if (left.size() > 0 && num < left.top()) {
        left.push(num);
        num = left.top();
        left.pop();
      }
      right.push(num);
    } else {
      // 总元素为奇数，且 right 的元素肯定比 left 多
      if (right.size() > 0 && num >= right.top()) {
        right.push(num);
        num = right.top();
        right.pop();
      }
      left.push(num);
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return ((double) left.top() + right.top()) / 2;
    } else {
      return right.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)

}