//
// Created by timking.nf@foxmail.com on 2021/1/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_03_05.sort-of-stacks-lcci.h"

namespace LeetCode_03_05 {

typedef vector<string> operators;
typedef vector<vector<int>> operator_argument;
typedef tuple<operators, operator_argument> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_03_05Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_03_05Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ostringstream os;
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  operators ops;
  operator_argument args;
  tie(ops, args) = argument;

  SortedStack stk;
  for (int i = 0; i < ops.size(); ++i) {
    if (ops[i] == "SortedStack") {
      stk = SortedStack();
      os << "null,";
    } else if (ops[i] == "push") {
      stk.push(args[i][0]);
      os << "null,";
    } else if (ops[i] == "pop") {
      stk.pop();
      os << "null,";
    } else if (ops[i] == "peek") {
      os << stk.peek() << ",";
    } else if (ops[i] == "isEmpty") {
      os << (stk.isEmpty() ? "true" : "false") << ",";
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);

  // 测试构造排序
  // stack<int> stk1;
  // stk1.push(5);
  // stk1.push(2);
  // stk1.push(3);
  // stk1.push(1);
  // SortedStack stk2 = SortedStack(stk1);
  // string oss2;
  // while (!stk2.isEmpty()) {
  //   oss2 += to_string(stk2.peek());
  //   stk2.pop();
  // }
  // ASSERT_EQ(oss2, "1235");
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"SortedStack", "push", "push", "peek", "pop", "peek"},
                         {{},{1},{2},{},{},{}}),
            "null,null,null,1,null,2"),
  ParamType(ArgumentType({"SortedStack", "pop", "pop", "push", "pop", "isEmpty"},
                         {{},{},{},{1},{},{}}),
            "null,null,null,null,null,true")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_03_05ParamTest, LeetCode_03_05Test, values);

}