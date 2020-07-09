//
// Created by timking.nf@foxmail.com on 2020/6/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_47.li-wu-de-zui-da-jie-zhi-lcof.h"

namespace LeetCode_47 {

typedef vector<vector<int>> MatrixType;
typedef MatrixType ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_47Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_47Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_47::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->maxValue(arguments), ret);  // 断言结果
}

ArgumentType p1{{1,3,1}, {1,5,1}, {4,2,1}};

auto values = ::testing::Values(
  ParamType(p1, 12)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_47ParamTest, LeetCode_47Test, values);

}