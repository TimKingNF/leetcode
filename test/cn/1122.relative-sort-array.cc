//
// Created by timking.nf@foxmail.com on 2020/11/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1122.relative-sort-array.h"

namespace LeetCode1122 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1122Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1122Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1122::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> arr1, arr2;
  tie(arr1, arr2) = arguments;

  ASSERT_EQ(solution->relativeSortArray(arr1, arr2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({2,3,1,3,2,4,6,7,9,2,19}, {2,1,4,3,9,6}),
            {2,2,2,1,4,3,3,9,6,7,19})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1122ParamTest, LeetCode1122Test, values);

}