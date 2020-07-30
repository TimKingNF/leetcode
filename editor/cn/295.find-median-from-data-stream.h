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
  // 使用max作为最大堆存储在中位数左边的元素
  // 使用min作为最小对存储在中位数右边的元素
  vector<int> min, max;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
      // 如果当前总数为偶数, 就将num加入到最小堆, 实现平均分配元素到 min 和 max 中
      if (((min.size() + max.size()) & 1) == 0) {
        // 如果要插入的数大于max的最大值
        // 就从插入之后的 max 中取出最大值插入到最小堆 min，保证 max 的值都小于 min
        if (max.size() > 0 && num < max[0]) {
          max.push_back(num);
          push_heap(max.begin(), max.end(), less<int>());  // 调整堆
          num = max[0];
          pop_heap(max.begin(), max.end(), less<int>());
          max.pop_back();
        }
        min.push_back(num);
        push_heap(min.begin(), min.end(), greater<int>());
      } else {
        if (min.size() > 0 && min[0] < num) {
          min.push_back(num);
          push_heap(min.begin(), min.end(), greater<int>());
          num = min[0];
          pop_heap(min.begin(), min.end(), greater<int>());
          min.pop_back();
        }
        max.push_back(num);
        push_heap(max.begin(), max.end(), less<int>());
      }
    }
    
    double findMedian() {
      if ((min.size() + max.size()) & 1) {
        return min[0];
      } else {
        return ((double) min[0] + max[0]) / 2;
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