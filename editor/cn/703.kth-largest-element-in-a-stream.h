//设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。 
//
// 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返
//回当前数据流中第K大的元素。 
//
// 示例: 
//
// 
//int k = 3;
//int[] arr = [4,5,8,2];
//KthLargest kthLargest = new KthLargest(3, arr);
//kthLargest.add(3);   // returns 4
//kthLargest.add(5);   // returns 5
//kthLargest.add(10);  // returns 5
//kthLargest.add(9);   // returns 8
//kthLargest.add(4);   // returns 8
// 
//
// 说明: 
//你可以假设 nums 的长度≥ k-1 且k ≥ 1。 
// Related Topics 堆

#include "header.h"

namespace LeetCode703 {

//leetcode submit region begin(Prohibit modification and deletion)
class KthLargest {
 private:
  int k;
  // priority_queue<int, vector<int>, greater<>> pq;  // 小顶堆
  struct TreeNode {
    int val;
    int count;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr), count(1) {};
  };
  TreeNode* root = nullptr;
public:
    // KthLargest(int k, vector<int>& nums) : k(k) {
    //   for (int n : nums) {
    //     pq.push(n);
    //     if (pq.size() > k) pq.pop();
    //   }
    // }
    //
    // int add(int val) {
    //   pq.push(val);
    //   if (pq.size() > k) pq.pop();
    //   return pq.top();
    // }

  KthLargest(int k, vector<int>& nums) : k(k) {
    for (int n : nums) root = addNode(root, n);
  }

  int add(int val) {
    root = addNode(root, val);
    return findNum(root, k);
  }

  TreeNode* addNode(TreeNode* node, int val) {
    if (!node) return new TreeNode(val);
    node->count += 1;
    if (val <= node->val) node->left = addNode(node->left, val);
    else node->right = addNode(node->right, val);
    return node;
  }

  int findNum(TreeNode* node, int k) {
    int m = 1;
    if (node->right) m = node->right->count + 1;
    if (k == m) return node->val;
    if (k < m) return findNum(node->right, k);  // 右子树的节点大于k，目标点在右子树
    return findNum(node->left, k-m);
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//leetcode submit region end(Prohibit modification and deletion)

}