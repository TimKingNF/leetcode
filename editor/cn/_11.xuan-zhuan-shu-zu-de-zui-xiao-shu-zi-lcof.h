//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2
//] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。 
//
// 示例 1： 
//
// 输入：[3,4,5,1,2]
//输出：1
// 
//
// 示例 2： 
//
// 输入：[2,2,2,0,1]
//输出：0
// 
//
// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sor
//ted-array-ii/ 
// Related Topics 二分查找

#include "header.h"

namespace LeetCode_11 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minArray(vector<int>& numbers) {
      int n = numbers.size();
      while (n > 0 && numbers[n - 1] == numbers[0]) {
        --n;
      }
      int l = -1, r = n, m;
      while (r - l > 1) {
        m = (r + l) / 2;
        if (numbers[m] >= numbers[0]) {
          l = m;
        } else {
          r = m;
        }
      }
      return r == n ? numbers[0] : numbers[r];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}