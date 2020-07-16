//统计所有小于非负整数 n 的质数的数量。 
//
// 示例: 
//
// 输入: 10
//输出: 4
//解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
// Related Topics 哈希表 数学

#include "header.h"

namespace LeetCode204 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
      return solution1(n);
    }

    // 判断数是否是质数
    // 常规的思路，判断质数, 是 2 - sqrt(n), 有一个能被整除即不是质数
    // 另一种思路：费马小定理, 但对有些数可能出错, 这种数被称为 "绝对伪素数", 如 561, 1105
    // 对每个质数，均成立有 p < n, p^n mod n = p, 故只要有一个不成立即不是质数
    // 如对5而言
    // 1^5 = 1 mod 5 = 1
    // 2^5 = 32 mod 5 = 2
    // 3^5 = 243 mod 5 = 3
    // 4^5 = 1024 mod 5 = 4
    int isPrime(int n) {
      // for (int i = n-1; i >= 1; --i) {
      //   if ((int) pow(i, n) % n != i) return false;
      // }
      // return true;
      for (int i = 2; i <= (int) sqrt(n); ++i) {
        if (n % i == 0) return false;
      }
      return true;
    }

    // TODO
    // 已知2是质数，那么所有2的倍数就不是质数
    // 同理，3是质数，那么所有的3的倍数就不是质数
    // 最后剩下的数就是质数
    int solution1(int n) {
      int ans = 0;
      vector<bool> signs(n, true);
      for (int i = 2; i < n; i++) {
        if (signs[i]) {
          ++ans;
          // 排除倍数
          for (int j = i + i; j < n; j += i) signs[j] = false;
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}