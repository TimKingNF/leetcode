//
// Created by timking.nf@foxmail.com on 2020/7/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "200.number-of-islands.h"

namespace LeetCode200 {

typedef vector<vector<char>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode200Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode200Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode200::Solution();
  ArgumentType arguments;
  int ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->numIslands(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{'1','1','1','1','0'},
             {'1','1','0','1','0'},
             {'1','1','0','0','0'},
             {'0','0','0','0','0'}}, 1),
  ParamType({{'1','1','0','0','0'},
             {'1','1','0','0','0'},
             {'0','0','1','0','0'},
             {'0','0','0','1','1'}}, 3),
  ParamType({{'1'}, {'1'}}, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode200ParamTest, LeetCode200Test, values);

}