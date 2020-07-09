//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 堆 分治算法

#include "header.h"

namespace LeetCode_40 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      return solution3(arr, k);
    }

    typedef multiset<int, greater<int>> intSet;

    // 不修改原数组，利用 multiset 红黑树 来实现最大堆, O(N logK)
    // 适用于极大数据量的情况
    vector<int> solution1(vector<int>& arr, int k) {
      if (arr.empty() || k <= 0) return {};
      if (arr.size() <= k) return arr;

      intSet leastNumbers;
      for (auto v : arr) {
        if (leastNumbers.size() < k)
          leastNumbers.insert(v);
        else {
          // 和 leastNumbers 最大值比较
          if (*leastNumbers.begin() > v)  {
            leastNumbers.erase(leastNumbers.begin());
            leastNumbers.insert(v);
          }
        }
      }
      return vector<int>(leastNumbers.begin(), leastNumbers.end());
    }

    // 排序并获取
    vector<int> solution2(vector<int>& arr, int k) {
      sort(arr.begin(), arr.end());
      return vector<int>(arr.begin(), arr.begin()+k);
    }

    // 利用快排的思想，随机选一个数，下标为index，将小于该数都放在 index 的左边，大于该数都放在 index 右边
    // 则此时 index 左刚好是 前index+1个数，如果 k < index + 1, 则 调整 right 为 index - 1, 否则调整 left 为 index + 1
    vector<int> solution3(vector<int>& arr, int k) {
      if (arr.empty() || k <= 0) return {};
      if (arr.size() <= k) return arr;
      srand((unsigned)time(NULL));

      int left = 0, right = arr.size() - 1;
      int index = partition(arr, left, right);
      while (index + 1 != k) {
        if (k < index + 1) {
          right = index - 1;
          index = partition(arr, left, right);
        } else {
          left = index + 1;
          index = partition(arr, left, right);
        }
      }
      return vector<int>(arr.begin(), arr.begin() + k);
    }

    int partition(vector<int>& nums, int l, int r) {
      int pivot_index = rand() % (r - l + 1) + l;
      swap(nums[r], nums[pivot_index]);
      int i = l - 1, pivot = nums[r];
      for (int j = l; j < r; ++j) {
        if (nums[j] < pivot)
          swap(nums[++i], nums[j]);
      }
      swap(nums[++i], nums[r]);  // 再调整回来
      return i;  // 返回交换之后的分界数下标
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}