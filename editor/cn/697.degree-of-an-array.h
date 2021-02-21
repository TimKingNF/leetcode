//给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。 
//
// 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。 
//
// 示例 1: 
//
// 
//输入: [1, 2, 2, 3, 1]
//输出: 2
//解释: 
//输入数组的度是2，因为元素1和2的出现频数最大，均为2.
//连续子数组里面拥有相同度的有如下所示:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//最短连续子数组[2, 2]的长度为2，所以返回2.
// 
//
// 示例 2: 
//
// 
//输入: [1,2,2,3,1,4,2]
//输出: 6
// 
//
// 注意: 
//
// 
// nums.length 在1到50,000区间范围内。 
// nums[i] 是一个在0到49,999范围内的整数。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode697 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
      return solution2(nums);
    }

    int solution1(vector<int>& nums) {
      int len = nums.size();
      unordered_map<int, int> degree;
      unordered_map<int, vector<int>> index;
      int degree_max = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (++degree[nums[i]] > degree_max)
          degree_max = degree[nums[i]];  // 记录最大度数

        if (index.find(nums[i]) == index.end())
          index[nums[i]] = vector<int>(2, i);  // 记录该元素的最左下标
        else
          index[nums[i]][1] = i;  // 记录该元素的最右下标
      }

      int res = nums.size();  // res 最大长度等于原数组
      // 可能含有多个相同数有相同的度
      for (auto pair : degree) {
        int k = pair.first, v = pair.second;
        if (v == degree_max)
          res = min(res, index[k][1] - index[k][0] + 1);
      }
      return res;
    }

    // 一次遍历
    int solution2(vector<int>& nums) {
      // vector 中记录首次出现起点，最后一次出现位置和出现次数
      unordered_map<int, vector<int>> dict;
      int max_key = nums[0];  // 出现最多次数的key
      dict[nums[0]] = {0, 0, 1};

      for (int i = 1; i < nums.size(); ++i) {
        if (dict.count(nums[i])) {
          // 和 max_key 做比较
          if (dict[nums[i]][2] + 1 > dict[max_key][2]) {
            max_key = nums[i];
          } else if (dict[nums[i]][2] + 1 == dict[max_key][2]) {  // == 的情况，max_key 取两者之前距离更小的
            int max_key_distance = dict[max_key][1] - dict[max_key][0] + 1;
            int distance = i - dict[nums[i]][0] + 1;
            max_key = distance < max_key_distance ? nums[i] : max_key;
          }
          dict[nums[i]][1] = i;  // 更新最后出现的位置
          dict[nums[i]][2]++;  // 更新出现次数
        } else {
          dict[nums[i]] = {i, i, 1};
        }
      }
      return dict[max_key][1] - dict[max_key][0] + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}