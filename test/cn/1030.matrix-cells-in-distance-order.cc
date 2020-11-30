//
// Created by timking.nf@foxmail.com on 2020/11/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1030.matrix-cells-in-distance-order.h"

namespace LeetCode1030 {

typedef tuple<int, int, int, int> ArgumentType;
typedef set<vector<vector<int>>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1030Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1030Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1030::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int R, C, r0, c0;
  tie(R, C, r0, c0) = arguments;

  vector<vector<int>> asserted = solution->allCellsDistOrder(R, C, r0, c0);
  // for (auto& v : asserted) {
  //   vector_print(v);
  // }
  ASSERT_TRUE(ret.count(asserted));
}

auto values = ::testing::Values(
  ParamType(ArgumentType(1, 2, 0, 0), {
    {{0,0}, {0,1}}
  }),
  ParamType(ArgumentType(2, 2, 0, 1), {
    {{0,1}, {0,0}, {1,1}, {1,0}},
    {{0,1}, {1,1}, {0,0}, {1,0}},
  }),
  ParamType(ArgumentType(2, 3, 1, 2), {
    {{1,2},{0,2},{1,1},{0,1},{1,0},{0,0}},
    {{1,2},{1,1},{0,2},{1,0},{0,1},{0,0}},
  })
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1030ParamTest, LeetCode1030Test, values);

}