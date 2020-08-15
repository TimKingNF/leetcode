//给定两个数组，编写一个函数来计算它们的交集。 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
// 
//
// 示例 2： 
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4] 
//
// 
//
// 说明： 
//
// 
// 输出结果中的每个元素一定是唯一的。 
// 我们可以不考虑输出结果的顺序。 
// 
// Related Topics 排序 哈希表 双指针 二分查找

#include "header.h"

namespace LeetCode349 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      return solution1(nums1, nums2);
    }

    // 哈希表 O(nm), O(n+m)
    vector<int> solution1(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.size() > nums2.size()) swap(nums1, nums2);
      unordered_set<int> dict(nums1.begin(), nums1.end());
      vector<int> ans;
      for (int n : nums2) {
        if (dict.count(n)) {
          ans.push_back(n);
          dict.erase(n);
        }
      }
      return ans;
    }

    // 二分解法, 需要排序 O(n logN + N), O(N)
    vector<int> solution2(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.empty() || nums2.empty()) return {};
      if (nums1.size() < nums2.size()) swap(nums1, nums2);
      set<int> ans;
      sort(nums2.begin(), nums2.end());  // 排序短的数组
      for (int v : nums1) {
        if (bSearch(nums2, v)) ans.insert(v);
      }
      return vector<int>(ans.begin(), ans.end());
    }

    bool bSearch(vector<int>& nums, int find) {
      int left = 0, right = nums.size() - 1, middle;
      while (left <= right) {
        middle = left + (right - left) / 2;
        if (find == nums[middle]) return true;
        if (find > nums[middle]) left = middle + 1;
        else right = middle - 1;
      }
      return false;
    }

    // 双指针，两个数组都排序，然后滑动比较
    vector<int> solution3(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.empty() || nums2.empty()) return {};
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      int i = 0, j = 0, i_cur, j_cur;
      vector<int> ans;
      while (i < nums1.size() && j < nums2.size()) {
        i_cur = nums1[i];
        j_cur = nums2[j];
        // 最后一个与 i_pre 相同的元素
        while (i + 1 < nums1.size() && nums1[i+1] == i_cur) {
          ++i;
        }
        // 最后一个与 j_pre 相同的元素
        while (j + 1 < nums2.size() && nums2[j+1] == j_cur) {
          ++j;
        }
        if (nums1[i] == nums2[j]) ans.push_back(nums1[i]);
        if (nums1[i] > nums2[j]) ++j;
        else ++i;
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}