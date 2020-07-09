//从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任
//意数字。A 不能视为 14。 
//
// 
//
// 示例 1: 
//
// 输入: [1,2,3,4,5]
//输出: True 
//
// 
//
// 示例 2: 
//
// 输入: [0,0,1,2,5]
//输出: True 
//
// 
//
// 限制： 
//
// 数组长度为 5 
//
// 数组的数取值为 [0, 13] . 
//

#include "header.h"

namespace LeetCode_61 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 题目的隐形条件，0 最多只有2张
    // 长度固定为5
    // 可能抽出重复的牌，且最多4张
    bool isStraight(vector<int>& nums) {
      return solution1(nums);
    }

    bool solution1(vector<int>& nums) {
      // if (nums.empty()) return false;  // 长度固定为5，不用判断也可
      int max_num = -1, min_num = 14;  // 0 最多只有两张
      int tmp[14] = {0};  // 均初始化为0, 用于记录1-13

      // 计算除0以外的最大值和最小值
      for (int v : nums) {
        if (v) {
          if (tmp[v]) return false;  // 只要抽出一张重复的牌，就不是顺子
          max_num = max(max_num, v);
          min_num = min(min_num, v);
          tmp[v] = 1;
        }
      }
      return max_num - min_num < 5;  // 非0的最大值减最小值 < 5, 即可说明是顺子
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}