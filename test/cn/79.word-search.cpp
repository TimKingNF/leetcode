//
// Created by timking.nf@foxmail.com on 2020/7/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "79.word-search.h"

namespace LeetCode79 {

typedef vector<vector<char>> MatrixType;
typedef tuple<MatrixType, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode79Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode79Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode79::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  MatrixType board;
  string word;
  tie(board, word) = arguments;

  ASSERT_EQ(solution->exist(board, word), ret);  // 断言结果
}


MatrixType p1_0{{'a','b','c','e'},
                {'s','f','c','s'},
                {'a','d','e','e'}};
ArgumentType p1(p1_0, "abfb");

MatrixType p2_0{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
ArgumentType p2(p2_0, "ABCCED");

MatrixType p3_0{{'a','b'},{'c','d'}};
ArgumentType p3(p3_0, "abcd");

MatrixType p4_0{{'a','a'}};
ArgumentType p4(p4_0, "aa");

MatrixType p5_0{{'C','A','A'},{'A','A','A'},{'B','C','D'}};
ArgumentType p5(p5_0, "AAB");

auto values = ::testing::Values(
  ParamType(p1, false),
  ParamType(p2, true),
  ParamType(p3, false),
  ParamType(p4, true),
  ParamType(p5, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode79ParamTest, LeetCode79Test, values);

}