//编写一个算法来判断一个数 n 是不是快乐数。 
//
// 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果 可以变为 1，那么这个数就是快乐数。 
//
// 如果 n 是快乐数就返回 True ；不是，则返回 False 。 
//
// 
//
// 示例： 
//
// 输入：19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
// 
// Related Topics 哈希表 数学

#include "header.h"

namespace LeetCode202 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isHappy(int n) {
      return solution1(n);
    }

    int getNext(int v) {
      int ans = 0;
      while (v > 0) {
        int d = v % 10;
        v /= 10;
        ans += d * d;
      }
      return ans;
    }

    // 只要有一次和出现在已经出现过的列表，说明该数循环，不为快乐数
    // 只有满足 n 为 10 的幂次才能得到 1
    bool solution1(int n) {
      set<int> sum_dict;
      while (n != 1 && !sum_dict.count(n)) {
        sum_dict.insert(n);
        n = getNext(n);
      }
      return n == 1;
    }

    // 快慢指针法
    bool solution2(int n) {
      int slow = n;
      int fast = getNext(n);
      while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(fast);
      }
      return fast == 1;  // 如果fast不为1，则说明存在环
    }

    // 数学
    // 所有数，最后都会递减到3位数，且小于243 (999的下一个数)
    // 在所有小于243的数中，已经有一部分数会陷入循环，故直接判断如果下一个数在这些数的范围，则不是快乐数
    bool solution3(int n) {
      set<int> cycleMembers = {4,16,37,58,89,145,42,20};
      while (n != 1 && !cycleMembers.count(n)) {
        n = getNext(n);
      }
      return n == 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}