//
// Created by timking.nf@foxmail.com on 2020/9/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "37.sudoku-solver.h"

namespace LeetCode37 {

typedef vector<vector<char>> ArgumentType;
typedef vector<vector<char>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode37Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode37Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode37::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->solveSudoku(argument);
  ASSERT_EQ(argument, ret);
}



auto values = ::testing::Values(
  ParamType({{'5','3','.','.','7','.','.','.','.'},
             {'6','.','.','1','9','5','.','.','.'},
             {'.','9','8','.','.','.','.','6','.'},
             {'8','.','.','.','6','.','.','.','3'},
             {'4','.','.','8','.','3','.','.','1'},
             {'7','.','.','.','2','.','.','.','6'},
             {'.','6','.','.','.','.','2','8','.'},
             {'.','.','.','4','1','9','.','.','5'},
             {'.','.','.','.','8','.','.','7','9'}},
            {{'5','3','4','6','7','8','9','1','2'},
             {'6','7','2','1','9','5','3','4','8'},
             {'1','9','8','3','4','2','5','6','7'},
             {'8','5','9','7','6','1','4','2','3'},
             {'4','2','6','8','5','3','7','9','1'},
             {'7','1','3','9','2','4','8','5','6'},
             {'9','6','1','5','3','7','2','8','4'},
             {'2','8','7','4','1','9','6','3','5'},
             {'3','4','5','2','8','6','1','7','9'}}
            )
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode37ParamTest, LeetCode37Test, values);

}