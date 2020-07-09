//求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。 
//
// 
//
// 示例 1： 
//
// 输入: n = 3
//输出: 6
// 
//
// 示例 2： 
//
// 输入: n = 9
//输出: 45
// 
//
// 
//
// 限制： 
//
// 
// 1 <= n <= 10000 
// 
//

#include "header.h"

namespace LeetCode_64 {

//leetcode submit region begin(Prohibit modification and deletion)
class Tmp {
 private:
  static int cur, Sum;
 public:
  static void reset() { cur = 0; Sum = 0;}
  static int get_sum() {return Sum;}
  Tmp() { ++cur; Sum += cur;}
};
int Tmp::cur = 0;
int Tmp::Sum = 0;

class Solution {
private:
    // 定义一个函数类型
    typedef int (*fun)(int);
public:
    int sumNums(int n) {
      return solution3(n);
    }

    // 使用递归, 但是还是使用了判断语句
    int solution1(int n) {
      n != 0 && (n += solution1(n-1));
      return n;
    }

    // 利用静态变量, 多次调用构造函数
    int solution2(int n) {
      Tmp::reset();
      Tmp* a = new Tmp[n];
      delete []a;
      return Tmp::get_sum();
    }

    static int solution3core(int n) {return 0;}

    static int solution3(int n) {
      static fun f[2] = {solution3core, solution3};
      return n + f[!!n](n-1);  // 递归，利用两次取反来转为0和1，当n为0时返回0
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}