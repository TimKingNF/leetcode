//
// Created by timking.nf@foxmail.com on 2020/7/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "498.diagonal-traverse.h"

namespace LeetCode498 {

typedef vector<vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode498Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode498Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode498::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findDiagonalOrder(argument), ret);  // 断言结果
}



auto values = ::testing::Values(
  ParamType({{ 1, 2, 3 },
             { 4, 5, 6 },
             { 7, 8, 9 }},
            {1,2,4,7,5,3,6,8,9})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode498ParamTest, LeetCode498Test, values);

}