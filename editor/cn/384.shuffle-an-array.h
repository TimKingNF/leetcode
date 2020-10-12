//打乱一个没有重复元素的数组。 
//
// 
//
// 示例: 
//
// // 以数字集合 1, 2 和 3 初始化数组。
//int[] nums = {1,2,3};
//Solution solution = new Solution(nums);
//
//// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
//solution.shuffle();
//
//// 重设数组到它的初始状态[1,2,3]。
//solution.reset();
//
//// 随机返回数组[1,2,3]打乱后的结果。
//solution.shuffle();
// 
//

#include "header.h"

namespace LeetCode384 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  vector<int> orig;
public:
    Solution(vector<int>& nums) : orig(nums) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
      return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      vector<int> res = orig;
      for (int i = 0; i < res.size(); ++i) {
        int t = i + rand() % (res.size() - i);  // i 之前的元素是已经固定选好的值
        swap(res[i], res[t]);
      }
      return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
//leetcode submit region end(Prohibit modification and deletion)

}