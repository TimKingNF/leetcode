//
// Created by timking.nf@foxmail.com on 2020/7/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "117.populating-next-right-pointers-in-each-node-ii.h"

namespace LeetCode117 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

string check(Node* root) {
  string ans = "";
  if (!root) return ans;
  deque<Node*> q;
  q.push_back(root);
  Node* cur;
  int size;
  while (!q.empty()) {
    size = q.size();
    cur = q.front();
    ans += to_string(cur->val) + ",";
    for (int i = 0; i < size; ++i) {
      cur = q.front();
      q.pop_front();
      if (cur->next) ans += to_string(cur->next->val) + ",";
      if (cur->left) q.push_back(cur->left);
      if (cur->right) q.push_back(cur->right);
    }
    ans += "#,";
  }
  return ans.substr(0, ans.length()-1);
}

class LeetCode117Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode117Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode117::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  Node* root = buildTreeBySerialize<Node, convert>(argument);
  solution->connect(root);

  // 验证
  ASSERT_EQ(check(root), ret);
}

auto values = ::testing::Values(
  ParamType("1,2,3", "1,#,2,3,#"),
  ParamType("1,2,3,4,5,6,7", "1,#,2,3,#,4,5,6,7,#"),
  ParamType("1,2,3,4,5,null,7", "1,#,2,3,#,4,5,7,#"),
  ParamType("3,9,20,null,null,15,7", "3,#,9,20,#,15,7,#"),
  ParamType("1,2,3,4,5,null,6,7,null,null,null,null,8", "1,#,2,3,#,4,5,6,#,7,8,#"),
  ParamType("0,2,4,1,null,3,-1,5,1,null,6,null,8", "0,#,2,4,#,1,3,-1,#,5,1,6,8,#")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode117ParamTest, LeetCode117Test, values);

}