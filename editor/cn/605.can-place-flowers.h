//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。 
//
// 给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True
//，不能则返回False。 
//
// 示例 1: 
//
// 
//输入: flowerbed = [1,0,0,0,1], n = 1
//输出: True
// 
//
// 示例 2: 
//
// 
//输入: flowerbed = [1,0,0,0,1], n = 2
//输出: False
// 
//
// 注意: 
//
// 
// 数组内已种好的花不会违反种植规则。 
// 输入的数组长度范围为 [1, 20000]。 
// n 是非负整数，且不会超过输入数组的大小。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode605 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      return solution2(flowerbed, n);
    }

    bool solution1(vector<int>& flowerbed, int n) {
      int i = 0, len = flowerbed.size();
      while ( i < len ) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == len - 1 || flowerbed[i+1] == 0)) {
          flowerbed[i] = 1;
          --n;
        }
        ++i;
      }
      return n <= 0;
    }

    // 跳格子
    bool solution2(vector<int>& flowerbed, int n) {
      if (n == 0) return true;
      int len = flowerbed.size();
      for (int i = 0; i < len; ) {
        if (flowerbed[i] == 1) {
          i += 2;  // 当前已经种了花，跳1格
        } else if (i == len - 1 || flowerbed[i+1] == 0) {  // 当前没有花，且后一格也没有花了
          if (--n <= 0) return true;  // 此格能种
          i += 2;
        } else {  // 后一格有花，需要跳3格
          i += 3;
        }
      }
      return false;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}