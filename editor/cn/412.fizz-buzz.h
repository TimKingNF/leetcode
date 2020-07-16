//写一个程序，输出从 1 到 n 数字的字符串表示。 
//
// 1. 如果 n 是3的倍数，输出“Fizz”； 
//
// 2. 如果 n 是5的倍数，输出“Buzz”； 
//
// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。 
//
// 示例： 
//
// n = 15,
//
//返回:
//[
//    "1",
//    "2",
//    "Fizz",
//    "4",
//    "Buzz",
//    "Fizz",
//    "7",
//    "8",
//    "Fizz",
//    "Buzz",
//    "11",
//    "Fizz",
//    "13",
//    "14",
//    "FizzBuzz"
//]
// 
//

#include "header.h"

namespace LeetCode412 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
      return solution2(n);
    }

    vector<string> solution1(int n) {
      vector<string> ans;
      string cur;
      for (int i = 1; i <= n; ++i) {
        cur = "";
        if (i % 3 == 0) cur += "Fizz";
        if (i % 5 == 0) cur += "Buzz";
        if (cur.empty()) cur = to_string(i);
        ans.push_back(cur);
      }
      return ans;
    }

    vector<string> solution2(int n) {
      vector<string> ans(n);
      // 从下标2开始，每3个表示3的倍数
      for (int i = 2; i < n; i+=3) ans[i] += "Fizz";
      for (int i = 4; i < n; i+=5) ans[i] += "Buzz";
      for (int i = 0; i < n; ++i) ans[i] = ans[i].empty() ? to_string(i+1) : ans[i];
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}