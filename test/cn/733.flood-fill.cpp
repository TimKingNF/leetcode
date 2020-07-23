//
// Created by timking.nf@foxmail.com on 2020/7/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "733.flood-fill.h"

namespace LeetCode733 {

typedef tuple<vector<vector<int>>, int, int, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode733Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode733Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode733::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<int>> image;
  int sr, sc, newColor;
  tie(image, sr, sc, newColor) = arguments;

  ASSERT_EQ(solution->floodFill(image, sr, sc, newColor), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{1,1,1}, {1,1,0}, {1,0,1}}, 1, 1, 2),
            {{2,2,2}, {2,2,0}, {2,0,1}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode733ParamTest, LeetCode733Test, values);

}