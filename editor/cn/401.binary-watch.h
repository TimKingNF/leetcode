//二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。 
//
// 每个 LED 代表一个 0 或 1，最低位在右侧。 
//
// 
//
// 例如，上面的二进制手表读取 “3:25”。 
//
// 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。 
//
// 
//
// 示例： 
//
// 输入: n = 1
//返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "
//0:32"] 
//
// 
//
// 提示： 
//
// 
// 输出的顺序没有要求。 
// 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。 
// 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。 
// 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。 
// 
// Related Topics 位运算 回溯算法

#include "header.h"

namespace LeetCode401 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
      return solution1(num);
    }

    vector<string> solution1(int num) {
      vector<string> ans;
      solution1core(num, 0, &ans);
      return ans;
    }

    void solution1core(int num, int16_t v, vector<string> *ans) {
      // 剪枝
      if ((v & 0x003F) >= 60 || ((v & 0x03C0) >> 6) >= 12) return;
      if (num == 0) {
        (*ans).push_back(getClock(v));
        return;
      }

      // 获取v的最低位1，从该位开始，避免重复计算
      // 如果 v == 0 则取 2^9
      int bit = !v ? 0x0200 : (v & -v);
      while (bit != 0) {
        if ((v & bit) == 0)  // 设置不为0的位为1
          solution1core(num - 1, v | bit, ans);
        bit >>= 1;
      }
    }

    string getClock(int16_t v) {
      int minute = v & 0x003F;  // 取代表分钟的低6位
      int hour = (v & 0x03C0) >> 6;  // 取代表小时的高4位
      char buf[6];
      snprintf(buf, 6, "%d:%02d", hour, minute);  // 算上最后的\0 一共6个char
      return (string) buf;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}