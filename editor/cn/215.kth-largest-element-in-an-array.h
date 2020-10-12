//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法

#include "header.h"

namespace LeetCode215 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      return solution3(nums, k);
    }

    // 排序之后第k个的元素
    // O( 2N ), O( N )
    int solution1(vector<int>& nums, int k) {
      map<int, int, greater<>> dict;  // 从大到小排序的 红黑数字典
      for (int n : nums) ++dict[n];
      for (auto iter : dict) {
        k -= iter.second;
        if (k <= 0) return iter.first;
      }
      return -1;
    }

    // 堆
    // O( N * logN ), O( k )
    int solution2(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<>> q;  // 最小堆
      for (int v : nums) {
        if (q.size() < k) {
          q.push(v);  // 直接插入
        } else {
          // 和当前最小堆中的最小值进行比较
          if (v > q.top()) {
            q.push(v);
            q.pop();
          }
        }
      }
      return q.top();
    }

    // 利用快排的思想，随机取一个元素分为两组
    // O( N )
    int solution3(vector<int>& nums, int k) {
      int n = nums.size();
      function<int(int, int)> partition = [&](int left, int right) {
        int v = nums[left];
        int j = left, i = left + 1;
        while (i <= right) {
          // 小于 j 的范围的数都比 v 大，大于 j 小于 i 的范围的数都比 v 小
          if (nums[i] >= v) swap(nums[++j], nums[i]);
          ++i;
        }
        swap(nums[left], nums[j]);
        return j;
      };

      function<int(int, int)> quickSort = [&](int left, int right) {
        if (left >= right) return left;
        int p = partition(left, right);
        if (p + 1 == k) return p;
        return p + 1 > k ? quickSort(left, p - 1) : quickSort(p + 1, right);
      };

      int idx = quickSort(0, n-1);
      return nums[idx];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}