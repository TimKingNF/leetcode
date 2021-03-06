//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数
//值排序之后中间两个数的平均值。 
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
// 示例 1： 
//
// 输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 
//
// 示例 2： 
//
// 输入：
//["MedianFinder","addNum","findMedian","addNum","findMedian"]
//[[],[2],[],[3],[]]
//输出：[null,null,2.00000,null,2.50000] 
//
// 
//
// 限制： 
//
// 
// 最多会对 addNum、findMedia进行 50000 次调用。 
// 
//
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-strea
//m/ 
// Related Topics 堆 设计

#include "header.h"

namespace LeetCode_41 {

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