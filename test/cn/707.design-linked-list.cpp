//
// Created by timking.nf@foxmail.com on 2020/7/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "707.design-linked-list.h"

namespace LeetCode707 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

vector<int> serializerMyLinkedList(MyLinkedList* root) {
  vector<int> ans;
  int i = 0, val = root->get(i++);
  while (val != -1) {
    ans.push_back(val);
    val = root->get(i++);
  }
  return ans;
}

class LeetCode707Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode707Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  MyLinkedList* linkedList;

  for (int i = 0; i < actions.size(); ++i) {
    // cout << actions[i] << endl;
    if (actions[i] == "MyLinkedList") {
      linkedList = new MyLinkedList();
    } else if (actions[i] == "addAtHead") {
      linkedList->addAtHead(inputs[i][0]);
      ASSERT_EQ(serializerMyLinkedList(linkedList), ret[i]);
    } else if (actions[i] == "addAtTail") {
      linkedList->addAtTail(inputs[i][0]);
      ASSERT_EQ(serializerMyLinkedList(linkedList), ret[i]);
    } else if (actions[i] == "addAtIndex") {
      linkedList->addAtIndex(inputs[i][0], inputs[i][1]);
      ASSERT_EQ(serializerMyLinkedList(linkedList), ret[i]);
    } else if (actions[i] == "get") {
      ASSERT_EQ(linkedList->get(inputs[i][0]), ret[i][0]);
    } else if (actions[i] == "deleteAtIndex") {
      linkedList->deleteAtIndex(inputs[i][0]);
      ASSERT_EQ(serializerMyLinkedList(linkedList), ret[i]);
    }
  }

}

auto values = ::testing::Values(
  ParamType(ArgumentType({"MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"},
                         {{},{1},{3},{1,2},{1},{1},{1}}),
            {{}, {1}, {1,3}, {1,2,3}, {2}, {1,3}, {3}}),
  ParamType(ArgumentType({"MyLinkedList","addAtHead","deleteAtIndex"},
                          {{},{1},{0}}),
            {{}, {1}, {}}),
  ParamType(ArgumentType({"MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"},
                         {{},{1},{3},{1,2},{1},{0},{0}}),
            {{},{1},{1,3},{1,2,3},{2},{2,3},{2}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode707ParamTest, LeetCode707Test, values);

}