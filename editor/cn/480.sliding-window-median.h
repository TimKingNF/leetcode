//中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。 
//
// 例如： 
//
// 
// [2,3,4]，中位数是 3 
// [2,3]，中位数是 (2 + 3) / 2 = 2.5 
// 
//
// 给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗
//口中元素的中位数，并输出由它们组成的数组。 
//
// 
//
// 示例： 
//
// 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。 
//
// 
//窗口位置                      中位数
//---------------               -----
//[1  3  -1] -3  5  3  6  7       1
// 1 [3  -1  -3] 5  3  6  7      -1
// 1  3 [-1  -3  5] 3  6  7      -1
// 1  3  -1 [-3  5  3] 6  7       3
// 1  3  -1  -3 [5  3  6] 7       5
// 1  3  -1  -3  5 [3  6  7]      6
// 
//
// 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。 
//
// 
//
// 提示： 
//
// 
// 你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。 
// 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。 
// 
// Related Topics Sliding Window 
// 👍 219 👎 0

#include "header.h"

namespace LeetCode480 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 private:
  class DualHeap {
   private:
    map<int, int> deleted;  // key：元素, val: 要删除的次数
    priority_queue<int, vector<int>, less<>> left;  // 大顶堆
    priority_queue<int, vector<int>, greater<>> right; // 小顶堆
    // leftSize 和 rightSize 记录扣除延迟删除的元素的堆大小, 用于保证调整堆平衡
    int k, leftSize, rightSize;

    // 满足 leftSize == rightSize || leftSize == rightSize + 1
    // 在添加或移除一个元素之后，需要调整 left 和 right 的平衡
    // 此时不满足上述条件有两种
    // 1. leftSize >= rightSize + 2
    // 2. leftSize < rightSize
    void makeBalance() {
      if (leftSize > rightSize + 1) {
        right.push(left.top());
        left.pop();
        --leftSize;
        ++rightSize;
        // 考虑 此时 left 堆顶元素是否是早已应该移除的元素
        prune(left);
      } else if (leftSize < rightSize) {
        left.push(right.top());
        right.pop();
        ++leftSize;
        --rightSize;
        prune(right);
      }
    }

    // 从堆顶弹出一个早已应该移除的元素，否则不做操作
    template <typename T>
    void prune(T& head) {
      while (!head.empty()) {
        int num = head.top();
        if (deleted.count(num)) {  // 说明堆顶元素早已该移除
          --deleted[num];
          if (deleted[num] == 0) deleted.erase(num);
          head.pop();
        } else break;  // 不做操作
      }
    }
   public:
    DualHeap(int k) : k(k), leftSize(0), rightSize(0) {}

    void insert(int num) {
      if (left.empty() || num <= left.top()) {
        left.push(num);
        ++leftSize;
      } else {
        right.push(num);
        ++rightSize;
      }
      makeBalance();
    }

    void erase(int num) {
      ++deleted[num];
      if (num <= left.top()) {
        --leftSize;  // left 需要移除一个元素
        if (num == left.top()) prune(left);
      } else {
        --rightSize;
        if (num == right.top()) prune(right);
      }
      makeBalance();
    }

    double getMedian() {
      return k % 2 ? left.top() : ((double) left.top() + right.top()) / 2;
    }
  };

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      return solution1(nums, k);
    }

    // 堆+延时删除
    vector<double> solution1(vector<int>& nums, int k) {
      int n = nums.size(), cnt = 0;
      vector<double> ans(n - k + 1);
      DualHeap heap = DualHeap(k);

      for (int i = 0; i < n; ++i) {
        if (i >= k) {  // 需要计算中位数了
          ans[cnt++] = heap.getMedian();
          heap.erase(nums[i-k]);
        }
        heap.insert(nums[i]);
      }
      ans[cnt++] = heap.getMedian();  // 加上最后一个
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}