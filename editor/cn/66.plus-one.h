//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。 
//
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
//
// 你可以假设除了整数 0 之外，这个整数不会以零开头。 
//
// 示例 1: 
//
// 输入: [1,2,3]
//输出: [1,2,4]
//解释: 输入数组表示数字 123。
// 
//
// 示例 2: 
//
// 输入: [4,3,2,1]
//输出: [4,3,2,2]
//解释: 输入数组表示数字 4321。
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode66 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      return solution2(digits);
    }

    // O(n) 2 copy
    vector<int> solution1(vector<int>& digits) {
      int len = digits.size();
      vector<int> res(digits.size()+1);
      copy(digits.begin(), digits.end(), res.begin()+1);

      int flag = 0;  // 进位标志
      res[len] += 1; // 加1
      int tmp;
      // 循环判断是否需要进位
      for (int i = len; i >= 0; --i) {
        tmp = res[i] + flag;
        if (tmp > 9) {
          res[i] = tmp % 10;
          flag = 1;
        } else {
          flag = 0;
          res[i] = tmp;
        }
      }
      if (res[0] == 0) {
        return vector<int>(res.begin()+1, res.end());
      }
      return res;
    }

    // O(n) not copy
    vector<int> solution2(vector<int>& digits) {
      int n = digits.size();
      for (int i=n-1; i>=0; --i){
        if (digits[i] == 9){
          digits[i] = 0;
        }
        else{
          digits[i]+=1;
          break;
        }
      }
      if(digits[0] == 0){
        digits[0] = 1;
        digits.push_back(0);
      }
      return digits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}