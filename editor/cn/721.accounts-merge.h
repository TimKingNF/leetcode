//给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其
//余元素是 emails 表示该账户的邮箱地址。 
//
// 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为
//人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。 
//
// 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：
//accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnn
//ybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Ma
//ry", "mary@mail.com"]]
//输出：
//[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
//["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
//解释：
//第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
//第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
//可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
//['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的
//。
// 
//
// 
//
// 提示： 
//
// 
// accounts的长度将在[1，1000]的范围内。 
// accounts[i]的长度将在[1，10]的范围内。 
// accounts[i][j]的长度将在[1，30]的范围内。 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 173 👎 0

#include "header.h"

namespace LeetCode721 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 private:
  class UnionFind {
   public:
    vector<int> parent;

    UnionFind(int n) {
      parent.resize(n);
      for (int i = 0; i < n; ++i) parent[i] = i;
    }

    void unionSet(int x, int y) {
      parent[find(y)] = find(x);
    }

    int find(int cur) {
      if (parent[cur] != cur) {
        parent[cur] = find(parent[cur]);  // 查找的同时压缩路径
      }
      return parent[cur];
    }
  };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      return solution1(accounts);
    }

    vector<vector<string>> solution1(vector<vector<string>>& accounts) {
      map<string, int> emailToIndex;
      map<string, string> emailToName;
      int emailsCount = 0;
      for (auto& account : accounts) {
        string& name = account[0];
        int size = account.size();
        for (int i = 1; i < size; ++i) {
          string& email = account[i];
          if (!emailToIndex.count(email)) {
            emailToIndex[email] = emailsCount++;
            emailToName[email] = name;
          }
        }
      }

      UnionFind uf(emailsCount);
      for (auto& account : accounts) {
        string& firstEmail = account[1];
        int firstIndex = emailToIndex[firstEmail];
        int size = account.size();
        // 进行 union
        for (int i = 2; i < size; ++i) {
          string& nextEmail = account[i];
          int nextIndex = emailToIndex[nextEmail];
          uf.unionSet(firstIndex, nextIndex);
        }
      }

      map<int, vector<string>> indexToEmails;
      for (auto& [email, _] : emailToIndex) {
        int idx = uf.find(emailToIndex[email]);  // 找到链接后的根节点
        // 将 email 添加在链接后的根节点上
        vector<string>& account = indexToEmails[idx];
        account.emplace_back(email);
        indexToEmails[idx] = account;
      }

      vector<vector<string>> merged;
      for (auto& [_, emails] : indexToEmails) {
        sort(emails.begin(), emails.end());
        string& name = emailToName[emails[0]];
        vector<string> account;
        account.emplace_back(name);
        for (auto& email : emails) {
          account.emplace_back(email);
        }
        merged.emplace_back(account);
      }
      return merged;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}