//给定一个二叉树，我们在树的节点上安装摄像头。 
//
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。 
//
// 计算监控树的所有节点所需的最小摄像头数量。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[0,0,null,0,0]
//输出：1
//解释：如图所示，一台摄像头足以监控所有节点。
// 
//
// 示例 2： 
//
// 
//
// 输入：[0,0,null,0,null,0,null,null,0]
//输出：2
//解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
// 
//
// 
//提示： 
//
// 
// 给定树的节点数的范围是 [1, 1000]。 
// 每个节点的值都是 0。 
// 
// Related Topics 树 深度优先搜索 动态规划

#include "header.h"

namespace LeetCode968 {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
      return solution1(root);
    }

    // DP
    int solution1(TreeNode* root) {
      Ret res = solution1core(root);
      // 根节点没有父节点，所以只从 withCam 和 noCamWatchByChild 中取最小值
      return min(res.withCam, res.noCamWatchByChild);
    }

private:
    struct Ret {
      int withCam;  // 当前 root 节点含有 监控时的 minCam 数
      int noCamWatchByDad;  // 当前 root 节点没有监控，但被父节点监控的 minCam 数
      int noCamWatchByChild;  // 当前 root 节点没有监控，但被子节点监控的 minCam 数
    };

    Ret solution1core(TreeNode* root) {
      // base case
      if (!root) {
        // 对于空节点，直接返回。 其中1001是最大值
        return {1001, 0, 0};
      }
      Ret left = solution1core(root->left);  // 获得左子树的相机数
      Ret right = solution1core(root->right);

      // 状态转移方程
      // root节点有相机, 则有3种情况
      // 1. 左孩子和右孩子都没有相机，被父节点监控
      // 2. 左孩子有相机，右孩子没有相机，被父节点监控
      // 3. 左孩子没有相机，被父节点监控，右孩子有相机
      int withCam = 1 + min(min(left.noCamWatchByDad + right.noCamWatchByDad,
                            left.withCam + right.noCamWatchByDad),
                            left.noCamWatchByDad + right.withCam);

      // root 节点没有相机，但被父节点监控，则对孩子节点，则有4种情况
      // 1. 左孩子和右孩子都有相机
      // 2. 左孩子有相机，右孩子没有相机，但被子节点监控（因为父节点没有相机)
      // 3. 左孩子没有相机，被子节点监控，右孩子有相机
      // 4. 左右孩子都没有相机，被子节点监控
      int noCamWatchByDad = min(min(min(left.withCam + right.withCam,
                                        left.withCam + right.noCamWatchByChild),
                                    left.noCamWatchByChild + right.withCam),
                                left.noCamWatchByChild + right.noCamWatchByChild);

      // root节点没有相机，但被子节点监控，则对孩子节点，有3种情况
      // 1. 左孩子和右孩子都有相机
      // 2. 左孩子有相机，右孩子没有相机，但被子节点监控（因为父节点没有相机)
      // 3. 左孩子没有相机，被子节点监控，右孩子有相机
      int noCamWatchByChild = min(min(left.withCam + right.withCam,
                                      left.withCam + right.noCamWatchByChild),
                                  left.noCamWatchByChild + right.withCam);
      return {withCam, noCamWatchByDad, noCamWatchByChild};
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}