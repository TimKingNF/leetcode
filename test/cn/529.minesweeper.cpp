//
// Created by timking.nf@foxmail.com on 2020/8/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "529.minesweeper.h"

namespace LeetCode529 {

typedef tuple<vector<vector<char>>, vector<int>> ArgumentType;
typedef vector<vector<char>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode529Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode529Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode529::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<char>> board;
  vector<int> click;
  tie(board, click) = arguments;

  ASSERT_EQ(solution->updateBoard(board, click), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{'E', 'E', 'E', 'E', 'E'},
                          {'E', 'E', 'M', 'E', 'E'},
                          {'E', 'E', 'E', 'E', 'E'},
                          {'E', 'E', 'E', 'E', 'E'}},
                         {3, 0}),
            {{'B', '1', 'E', '1', 'B'},
             {'B', '1', 'M', '1', 'B'},
             {'B', '1', '1', '1', 'B'},
             {'B', 'B', 'B', 'B', 'B'}}),
  ParamType(ArgumentType({{'B', '1', 'E', '1', 'B'},
                          {'B', '1', 'M', '1', 'B'},
                          {'B', '1', '1', '1', 'B'},
                          {'B', 'B', 'B', 'B', 'B'}},
                         {1,2}),
            {{'B', '1', 'E', '1', 'B'},
             {'B', '1', 'X', '1', 'B'},
             {'B', '1', '1', '1', 'B'},
             {'B', 'B', 'B', 'B', 'B'}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode529ParamTest, LeetCode529Test, values);

}