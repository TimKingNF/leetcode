//给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。 
//
// 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [1,2,2,1,1,3]
//输出：true
//解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。 
//
// 示例 2： 
//
// 输入：arr = [1,2]
//输出：false
// 
//
// 示例 3： 
//
// 输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 1000 
// -1000 <= arr[i] <= 1000 
// 
// Related Topics 哈希表 
// 👍 90 👎 0

#include "header.h"

namespace LeetCode1207 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      return solution1(arr);
    }

    // hash
    bool solution1(vector<int>& arr) {
      const int MAX_V = 1001;
      int dict[2001] = {0}, count[1001];
      fill(count, count + 1001, MAX_V);
      for (int num : arr) {
        dict[num + 1000]++;
      }
      // 这里也可以通过 set 去重之后比较去重前后的大小
      for (int i = -1000; i <= 1000; ++i) {
        if (dict[i + 1000] != 0) {  // 说明有次数
          int times = dict[i+1000];
          if (count[times] != MAX_V) return false;  // 说明次数重复出现过
          count[times] = i;  // 记录出现的次数和对应的数
        }
      }
      return true;
    }

    // solution2: 排序后，和上一次数出现的次数比较
};
//leetcode submit region end(Prohibit modification and deletion)

}