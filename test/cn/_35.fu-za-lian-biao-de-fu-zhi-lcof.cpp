//
// Created by timking.nf@foxmail.com on 2020/6/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_35.fu-za-lian-biao-de-fu-zhi-lcof.h"

namespace LeetCode_35 {

typedef vector<vector<int>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int null = -1;

Node* getNodeByIndex(Node* head, int i) {
  if (!head) return nullptr;
  if (i < 0) return nullptr;
  while (i > 0) {
    head = head->next;
    --i;
  }
  return head;
}

Node* constructComplexLinkList(vector<vector<int>>& nums) {
  // 先构造出顺序链表
  vector<int> tmp;
  for (auto v : nums)
    tmp.push_back(v[0]);
  Node* head = construct_link_list<Node>(tmp);
  // 按照 nums 赋值指定的 random
  Node* p = head;
  for (int i = 0; i < nums.size(); ++i, p = p->next) {
    if (nums[i][1] == null)
      continue;
    p->random = getNodeByIndex(head, nums[i][1]);
  }
  return head;
}

vector<vector<int>> printComplexLinkList(Node* head) {
  if (!head) return {};

  unordered_map<Node*, int> tmp;
  // 遍历记录指针和下标
  Node* p = head;
  int i = 0;
  while (p) {
    tmp.insert(pair<Node*, int>(p, i));
    ++i;
    p = p->next;
  }
  vector<vector<int>> ans;
  vector<int> line;
  while (head) {
    int index = null;
    auto search = tmp.find(head->random);
    if (search != tmp.end())
      index = search->second;
    line = {head->val, index};
    ans.push_back(line);
    head = head->next;
  }
  return ans;
}

class LeetCode_35Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_35Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_35::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  Node* head = constructComplexLinkList(argument);
  Node* copyHead = solution->copyRandomList(head);
  ASSERT_EQ(printComplexLinkList(copyHead), ret);
  ASSERT_TRUE( !head || head != copyHead);
}

vector<vector<int>> p1{{7,null},{13,0},{11,4},{10,2},{1,0}};

vector<vector<int>> p2{{1,1},{2,1}};

vector<vector<int>> p3{{3,null},{3,0},{3,null}};

vector<vector<int>> p4{};

auto values = ::testing::Values(
  ParamType(p1, p1)
  // ParamType(p2, p2),
  // ParamType(p3, p3),
  // ParamType(p4, p4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_35ParamTest, LeetCode_35Test, values);

}