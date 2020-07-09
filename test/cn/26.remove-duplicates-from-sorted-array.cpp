//
// Created by timking.nf@foxmail.com on 2020/5/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "26.remove-duplicates-from-sorted-array.h"

namespace LeetCode26 {

typedef tuple<vector<int>, int, vector<int>> ParamType;

class LeetCode26Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode26Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode26::Solution();
  vector<int> param;
  int len;
  vector<int> asserts;

  tie(param, len, asserts) = GetParam();

  //  ostream_iterator<int> out_it(cout, ", ");
  //  copy(param.begin(), param.end(), out_it);

  ASSERT_EQ(solution->removeDuplicates(param), len);

  vector<int> slice(param.begin(), param.begin() + len);
  ASSERT_EQ(slice, asserts);
}

vector<int> p1{1, 1, 2};
vector<int> p2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
vector<int> r1{1, 2};
vector<int> r2{0, 1, 2, 3, 4};
auto values = ::testing::Values(ParamType(p1, 2, r1), ParamType(p2, 5, r2));
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode26ParamTest, LeetCode26Test, values);

}