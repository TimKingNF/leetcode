//假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来
//重建这个队列。 
//
// 注意： 
//总人数少于1100人。 
//
// 示例 
//
// 
//输入:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//输出:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
// 
// Related Topics 贪心算法 
// 👍 613 👎 0

#include "header.h"

namespace LeetCode406 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      return solution1(people);
    }

    // O( n^2 )
    // h 相同，k 小的在前面，所以 k 应该是从小到大
    // 反之 h 应从大到小
    vector<vector<int>> solution1(vector<vector<int>>& people) {
      sort(people.begin(), people.end(), [](vector<int>& first, vector<int>& second) {
        if (first[0] == second[0]) return first[1] < second[1];  // h 相同，k 从小到大
        return first[0] > second[0];  // h 从大到小
      });
      list<vector<int>> q;  // 用 list 插入效率更好一点
      for (int i = 0; i < people.size(); ++i) {
        int position = people[i][1];  // 插入到下标为 position 的位置
        auto it = q.begin();
        advance(it, position);  // 移动下标
        q.insert(it, people[i]);
      }
      return vector<vector<int>>{q.begin(), q.end()};
    }

    // TODO: 树状数组
};
//leetcode submit region end(Prohibit modification and deletion)

}