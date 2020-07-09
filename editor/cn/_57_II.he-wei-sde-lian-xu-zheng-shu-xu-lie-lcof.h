//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。 
//
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。 
//
// 
//
// 示例 1： 
//
// 输入：target = 9
//输出：[[2,3,4],[4,5]]
// 
//
// 示例 2： 
//
// 输入：target = 15
//输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
//

#include "header.h"

namespace LeetCode_57_II {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
      return solution4(target);
    }

    // hash 法
    // 可以看成等差数列的差值为target
    // 计算从 0 到 target / 2 + 1的等差数列的和
    // 从中求任选两数相减等于target， 即为结果数列
    // O(N) O(N)
    vector<vector<int>> solution1(int target) {
      map<long, int> m;
      long sum;
      for (long i = 0; i <= target / 2 + 1; ++i) {
        sum = i * (i+1) / 2;  // 第几个数的等差和
        m[sum] = i;
      }
      vector<vector<int>> ans;
      for (auto v : m) {
        auto find = m.find(v.first - target);
        if (find != m.end()) {  // 说明存在
          ans.push_back(constructRange(find->second + 1, v.second));  // 不包括前一个数，所以需要+1
        }
      }
      return ans;
    }

    // 构造从 start 到 end
    vector<int> constructRange(int start, int end) {
      vector<int> ans;
      for (int i = start; i <= end; ++i) {
        ans.push_back(i);
      }
      return ans;
    }

    // 滑动窗口, O(N)
    vector<vector<int>> solution2(int target) {
      int sum = 0;
      vector<vector<int>> ans;
      deque<int> line;
      for (int i = 1; i <= target / 2 + 2; ++i) {
        while (sum > target) {
          int pop = line.front();
          line.pop_front();
          sum -= pop;
        }
        if (sum == target) {
          ans.push_back(convertVector(line));
        }
        line.push_back(i);
        sum += i;
      }
      return ans;
    }

    // 将deque 转为 vector
    vector<int> convertVector(deque<int>& q) {
      vector<int> ans;
      for (int i = 0; i < q.size(); ++i)
        ans.push_back(q[i]);
      return ans;
    }

    // 在滑动窗口的基础上再进行优化一下， 利用数学公式
    // 已知求等差数列为 n*(n+1)/2, 对于双指针的等差数列和，则有公式
    // n(x+y)/2 其中 n 为项数，x 为首项，y 为末项，其中 n=y-x+1
    vector<vector<int>> solution3(int target) {
      vector<vector<int>> ans;
      int sum;
      for (int l = 1, r = 2; l < r; ) {
        sum = (l + r) * (r - l + 1) / 2;
        if (sum == target) {
          ans.push_back(constructRange(l, r));
          l++;
        }
        else if (sum > target) l++;
        else r++;
      }
      return ans;
    }

    // 利用刚刚的数学公式再引申一下
    // 设 i=y-x 带入公式则有 (2x+i)*(i+1)/2 = target
    // 求得 x = (t - i*(i+1)/2) / (i+1)
    // 因为x为正整数，故 i*(i+1)/2 需小于 target，用这两个条件可以进行剪枝
    vector<vector<int>> solution4(int target) {
      int i = 1;
      vector<vector<int>> ans;
      int tmp = target - i*(i+1)/2;
      int x;
      while (tmp >= 2) {  // 因为x>=1, y>=2, 故i+1>=2, 由 i*(i+1)/2 < target 推得
        if (!(tmp % (i+1))) {  // 可以整除，说明满足 x 为正整数
          x = tmp / (i+1);  // 求解x
          ans.push_back(constructRange(x, x+i));  // 获取从 x 到 x+i 的数列
        }
        ++i;  // 检查下一个间隔
        tmp = target - i*(i+1)/2;
      }
      // 由于间隔由小到大，所以列表是由大到小的顺序放入的，需要翻转一下
      return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}

