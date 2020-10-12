//
// Created by timking.nf@foxmail.com on 2020/9/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "341.flatten-nested-list-iterator.h"

namespace LeetCode341 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

vector<NestedInteger> construct(string str) {
  int n = str.size();

  if (n == 0 || str[0] != '[' || str[n-1] != ']') return {};
  stack<int> stk;  // 记录 [ ] 的 下标
  vector<NestedInteger> ans;
  int level = 0;

  for (int i = 1; i < n-1; ++i) {  // 排除头尾 []
    char c = str[i];
    if (c == '[') {
      stk.push(i);
      level++;
    } else if (c == ']') {
      int start = stk.top();
      stk.pop();
      if (level == 1) {
        NestedInteger item(construct(str.substr(start, i-start+1)));
        ans.push_back(item);
      }
      level--;
    } else if (c >= '0' && c <= '9' && level == 0) {
      // 读取数字
      int num = c - '0';
      while (i + 1 < n - 1 && str[i+1] >= '0' && str[i+1] <= '9') {
        num = num * 10 + str[i+1] - '0';
        ++i;
      }
      ans.push_back(NestedInteger(num));
    }
    // 空格 逗号跳过
  }
  return ans;
}

void print(vector<NestedInteger>& data) {
  for (auto v : data) {
    if (v.isInteger()) {
      cout << v.getInteger() << " ";
    } else {
      cout << '[';
      vector<NestedInteger> item = v.getList();
      print(item);
      cout << "] ";
    }
  }
}

class LeetCode341Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode341Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<NestedInteger> nestedList = construct(argument);
  // print(nestedList);
  NestedIterator i(nestedList);
  vector<int> asserted;
  while (i.hasNext()) {
    asserted.push_back(i.next());
  }

  ASSERT_EQ(asserted, ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("[[1,1],2,[1,1]]", {1,1,2,1,1}),
  ParamType("[1,[4,[6]]]", {1,4,6}),
  ParamType("[1,[4,[6,2,[2]]]]", {1,4,6,2,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode341ParamTest, LeetCode341Test, values);

}