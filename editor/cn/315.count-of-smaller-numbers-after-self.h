//给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是 nums[i] 右侧小于 num
//s[i] 的元素的数量。 
//
// 
//
// 示例： 
//
// 输入：nums = [5,2,6,1]
//输出：[2,1,1,0] 
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法

#include "header.h"

namespace LeetCode315 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      return solution2(nums);
    }

    // 分治法
    // O( NlogN )
    vector<int> solution1(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n, 0);
      vector<int> idx(n);  // 用于记录对应下标的实际下标
      for (int i = 0; i < n; ++i) {
        idx[i] = i;
      }
      solution1core(nums, 0, n-1, idx, ans);
      return ans;
    }

    void solution1core(vector<int>& nums, int l, int r, vector<int>& idx, vector<int>& ans) {
      if (l >= r) return;
      int mid = l + (r - l) / 2;
      solution1core(nums, l, mid, idx, ans);
      solution1core(nums, mid + 1, r, idx, ans);
      merge(nums, l, mid, r, idx, ans);
    }

    void merge(vector<int>& nums, int l, int mid, int r, vector<int>& idx, vector<int>& ans) {
      int i = l, j = mid + 1, p = 0;
      vector<int> tmp(r-l+1), tmpIdx(r-l+1);

      while (i <= mid && j <= r) {
        // 左右比较直到 nums[i] <= nums[j] 则说明 nums[i] 右边从 mid+1 起有 j - mid - 1个元素小于它
        // [mid+1, j-1]
        if (nums[i] <= nums[j]) {
          tmp[p] = nums[i];
          tmpIdx[p] = idx[i];
          ans[idx[i]] += (j - mid - 1);
          ++i;
        } else {
          tmp[p] = nums[j];
          tmpIdx[p] = idx[j];
          ++j;
        }
        ++p;
      }
      while (i <= mid) {
        tmp[p] = nums[i];
        tmpIdx[p] = idx[i];
        ans[idx[i]] += (j - mid - 1);
        ++i;
        ++p;
      }
      while (j <= r) {
        tmp[p] = nums[j];
        tmpIdx[p] = idx[j];
        ++j;
        ++p;
      }
      // 将tmp 拷贝到 nums 中
      for (int k = 0; k < r-l+1; ++k) {
        idx[k+l] = tmpIdx[k];
        nums[k+l] = tmp[k];
      }
    }

   private:
    class FenwickTree {
      vector<int> tree;

     public:
      FenwickTree(int n) { tree = vector<int>(n+1); }

      // 单点更新：将 index 这个位置 +1
      void update(int i, int delta) {
        // 从下到上，最多到 size
        while (i <= tree.size()) {
          tree[i] += delta;
          i += (i & -i);  // i & -i 获得最低位的 1
        }
      }

      // 查询前缀和
      // 区间查询：查询小于等于 index 的元素个数
      int query(int i) {
        // 从右向左查询
        int sum = 0;
        while (i > 0) {
          sum += tree[i];
          i -= (i & -i);
        }
        return sum;
      }
    };

    // 树状数组
    // TODO
    vector<int> solution2(vector<int>& nums) {
      if (nums.empty()) return {};
      int n = nums.size();
      vector<int> ans;

      // 构建排名表，将数据离散化
      map<int, int> dict;
      int rank = 0;
      for (int num : set<int>(nums.begin(), nums.end())) {
        dict.insert({num, ++rank});  // 排名从 1 记起
      }

      FenwickTree *tree = new FenwickTree(dict.size() + 1);
      // 从后往前填表
      for (int i = n - 1; i >= 0; --i) {
        // 1. 查询排名
        rank = dict[nums[i]];
        // 2. 在树状数组排名的那个位置 + 1
        tree->update(rank, 1);
        // 3. 查询小于等于 "当前排名 -1" 的元素有多少
        ans.push_back(tree->query(rank - 1));
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}