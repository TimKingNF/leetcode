//
// Created by timking.nf@foxmail.com on 2020/5/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "661.image-smoother.h"

namespace LeetCode661 {

typedef vector<vector<int>> MatrixType;
typedef MatrixType ArgumentType;
typedef MatrixType ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode661Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode661Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode661::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->imageSmoother(argument), ret);  // 断言结果
}

ArgumentType p1{{1,1,1}, {1,0,1}, {1,1,1}};
ArgumentType p2{{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};

ResultType r1{{0,0,0}, {0,0,0}, {0,0,0}};
ResultType r2{{4,4,5},{5,6,6},{8,9,9},{11,12,12},{13,13,14}};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode661ParamTest, LeetCode661Test, values);

}
