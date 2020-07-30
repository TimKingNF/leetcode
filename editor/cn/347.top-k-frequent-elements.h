//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。 
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。 
// 你可以按任意顺序返回答案。 
// 
// Related Topics 堆 哈希表

#include "header.h"

namespace LeetCode347 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      return solution3(nums, k);
    }

    // hash
    // O( N + N * logK), O(N)
    vector<int> solution1(vector<int>& nums, int k) {
      unordered_map<int, int> dict;
      for (int v : nums) ++dict[v];
      // 将字典中的元素排序
      vector<pair<int, int>> vec;
      vec.reserve(dict.size());
      for (auto v : dict) vec.emplace_back(v);
      sort(vec.begin(), vec.end(), [&](pair<int, int> first, pair<int, int> second){
        return first.second > second.second;  // 按降序排序
      });
      vector<int> ans;
      ans.reserve(k);
      for (int i = 0; i < k; ++i) ans.push_back(vec[i].first);
      return ans;
    }

    // 堆排序
    // O(N + K * logK)
    vector<int> solution2(vector<int>& nums, int k) {
      unordered_map<int, int> dict;
      for (int v : nums) ++dict[v];
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;  // 最小堆
      for (auto it : dict) {
        if (q.size() == k) {
          // 堆满则比较 堆顶最小值和 当前元素的出现次数，如果当前元素的出现次数大于堆顶元素的出现次数，则出堆顶，push元素
          if (it.second > q.top().first) {
            q.pop();
            q.push({it.second, it.first});
          }
        } else q.push({it.second, it.first});
      }
      // 从堆中取出元素
      vector<int> ans;
      while (!q.empty()) {
        ans.push_back(q.top().second);
        q.pop();
      }
      return vector<int>(ans.rbegin(), ans.rend());
    }

    // 桶排序 O(N)
    vector<int> solution3(vector<int>& nums, int k) {
      unordered_map<int, int> dict;
      for (int v : nums) ++dict[v];

      // 用一个二维数组，统计次数作为第一维，如果统计次数相同，则追加
      vector<vector<int>> buckets(nums.size() + 1);
      for (auto iter : dict) buckets[iter.second].push_back(iter.first);

      // 将buckets中前k个高频元素加入到ans中
      vector<int> ans(k);
      int count = 0;
      for (int i = buckets.size() - 1; i >=0; --i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
          ans[count] = buckets[i][j];
          if (++count == k) return ans;
        }
      }
      return ans;
    }

  };
//leetcode submit region end(Prohibit modification and deletion)

}