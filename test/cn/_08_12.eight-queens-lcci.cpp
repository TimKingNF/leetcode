//
// Created by timking.nf@foxmail.com on 2020/8/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_08_12.eight-queens-lcci.h"

namespace LeetCode_08_12 {

typedef int ArgumentType;
typedef vector<vector<string>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_08_12Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_08_12Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_08_12::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<vector<string>> asserted = solution->solveNQueens(argument);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));  // 允许不同解法之间无序
}

auto values = ::testing::Values(
  ParamType(4, {{".Q..", "...Q", "Q...", "..Q."},
                {"..Q.", "Q...", "...Q", ".Q.."}}),
  ParamType(5, {{"Q....","..Q..","....Q",".Q...","...Q."},
                {"Q....","...Q.",".Q...","....Q","..Q.."},
                {".Q...","...Q.","Q....","..Q..","....Q"},
                {".Q...","....Q","..Q..","Q....","...Q."},
                {"..Q..","Q....","...Q.",".Q...","....Q"},
                {"..Q..","....Q",".Q...","...Q.","Q...."},
                {"...Q.","Q....","..Q..","....Q",".Q..."},
                {"...Q.",".Q...","....Q","..Q..","Q...."},
                {"....Q",".Q...","...Q.","Q....","..Q.."},
                {"....Q","..Q..","Q....","...Q.",".Q..."}})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_08_12ParamTest, LeetCode_08_12Test, values);

}