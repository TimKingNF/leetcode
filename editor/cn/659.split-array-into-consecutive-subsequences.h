//给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。 
//
// 如果可以完成上述分割，则返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 输入: [1,2,3,3,4,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 : 
//1, 2, 3
//3, 4, 5
// 
//
// 
//
// 示例 2： 
//
// 输入: [1,2,3,3,4,4,5,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 : 
//1, 2, 3, 4, 5
//3, 4, 5
// 
//
// 
//
// 示例 3： 
//
// 输入: [1,2,3,4,4,5]
//输出: False
// 
//
// 
//
// 提示： 
//
// 
// 输入的数组长度范围为 [1, 10000] 
// 
//
// 
// Related Topics 堆 贪心算法 
// 👍 196 👎 0

#include "header.h"

namespace LeetCode659 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
      return solution1(nums);
    }

    // 贪心
    bool solution1(vector<int>& nums) {
      unordered_map<int, int> count;
      unordered_map<int, int> end;
      for (auto& i : nums) count[i]++;

      for (auto& i : nums) {
        int cnt = count[i];
        if (cnt > 0) {  // 还有剩余数量，说明还没有被使用过
          // 考虑存在是否有以 i - 1 为结尾的队列
          int prevEndCount = end[i - 1];
          if (prevEndCount > 0) {  // 如果有，将 i 加入到此队列中
            count[i]--;  // 减去一个字符
            end[i-1]--;  // 以 i - 1 结尾的队列少一个
            end[i]++;  // 以 i 结尾的队列多一个
          } else {
            int cnt1 = count[i + 1];
            int cnt2 = count[i + 2];
            if (cnt1 && cnt2) {  // 此时说明可以构成子队列
              count[i]--;
              count[i+1]--;
              count[i+2]--;
              end[i+2]++;
            } else {
              return false;
            }
          }
        }
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}