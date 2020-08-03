//给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一
//样，优先选择数值较小的那个数。 
//
// 示例 1: 
//
// 
//输入: [1,2,3,4,5], k=4, x=3
//输出: [1,2,3,4]
// 
//
// 
//
// 示例 2: 
//
// 
//输入: [1,2,3,4,5], k=4, x=-1
//输出: [1,2,3,4]
// 
//
// 
//
// 说明: 
//
// 
// k 的值为正数，且总是小于给定排序数组的长度。 
// 数组不为空，且长度不超过 104 
// 数组里的每个元素与 x 的绝对值不超过 104 
// 
//
// 
//
// 更新(2017/9/19): 
//这个参数 arr 已经被改变为一个整数数组（而不是整数列表）。 请重新加载代码定义以获取最新更改。 
// Related Topics 二分查找

#include "header.h"

namespace LeetCode658 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      return solution3(arr, k, x);
    }

    // O(logN + K + K * logK)
    vector<int> solution1(vector<int>& arr, int k, int x) {
      // 先找距离x最近的数
      int n = arr.size(), left = 0, right = n - 1, middle, closeIndex;
      if (x <= arr[left]) return vector<int>(arr.begin(), arr.begin() + k);
      if (x >= arr[right]) return vector<int>(arr.end()-k, arr.end());

      while (left < right) {
        if (right - left == 1) {
          closeIndex = arr[right] - x >= x - arr[left] ? left : right;
          break;
        }
        middle = left + (right - left) / 2;
        if (arr[middle] == x) {
          closeIndex = middle;
          break;
        }
        else if (arr[middle] > x) right = middle;
        else left = middle;
      }

      // 从 closeIndex 向两侧扩展
      left = closeIndex - 1, right = closeIndex + 1;
      vector<int> ans;
      ans.push_back(arr[closeIndex]);
      for (int i = 1; i < k; ++i) {
        if (left >= 0 && right < n) {
          if (x - arr[left] <= arr[right] - x) {
            ans.push_back(arr[left]);
            --left;
          } else {
            ans.push_back(arr[right]);
            ++right;
          }
        } else if (left >= 0) {
          ans.push_back(arr[left]);
          --left;
        } else {
          ans.push_back(arr[right]);
          ++right;
        }
      }
      sort(ans.begin(), ans.end());
      return ans;
    }

    // 双指针法, O(N)
    vector<int> solution2(vector<int>& arr, int k, int x) {
       int n = arr.size();
       int left = 0, right = n - 1, removeNums = n - k;
       while (removeNums-- > 0) {
         if (x - arr[left] <= arr[right] - x) --right;  // 左边界离x更近
         else ++left;
       }
       // 计算得左边界
       return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }

    // 二叉查找，寻找最优区间的左边界 L
    // O(logN + k), O(1)
    vector<int> solution3(vector<int>& arr, int k, int x) {
      int n = arr.size();
      int left = 0, right = n - k;  // 最优区间的左边界取值只能在 [0, n-k] 中取
      int mid;
      while (left < right) {
        mid = left + (right - left) / 2;
        // 假设 mid 是左边界，则当前区间覆盖的范围是 [mid, mid + k].
        // 如果发现 arr[mid] 与 x 距离比 arr[mid + k] 与 x 的距离要大，说明 L 一定在mid右侧
        if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
        else right = mid;
      }
      // 计算得左边界
      return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}