//给定两个数组，编写一个函数来计算它们的交集。 
//
// 示例 1: 
//
// 输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2,2]
// 
//
// 示例 2: 
//
// 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出: [4,9] 
//
// 说明： 
//
// 
// 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。 
// 我们可以不考虑输出结果的顺序。 
// 
//
// 进阶: 
//
// 
// 如果给定的数组已经排好序呢？你将如何优化你的算法？ 
// 如果 nums1 的大小比 nums2 小很多，哪种方法更优？ 
// 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？ 
// 
// Related Topics 排序 哈希表 双指针 二分查找

#include "header.h"

namespace LeetCode350 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      return solution1(nums1, nums2);
    }

    // 如果 nums2 无法加载到内存中，则将 nums1 构建为 hash
    vector<int> solution1(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, int> dict;
      unordered_map<int, int>::iterator iter;
      for (int v : nums1) {
        iter = dict.find(v);
        // 记录数量
        if (iter != dict.end()) iter->second += 1;
        else dict.insert({v, 1});
      }
      vector<int> ans;
      for (int v : nums2) {
        iter = dict.find(v);
        if (iter != dict.end() && iter->second > 0) {
          ans.push_back(iter->first);
          if (--iter->second == 0) dict.erase(iter);  // 减少dict可以更快的 find
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}