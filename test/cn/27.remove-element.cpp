//
// Created by timking.nf@foxmail.com on 2020/5/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "27.remove-element.h"

namespace LeetCode27 {

typedef pair<vector<int>, int> ArgumentType;
typedef tuple<ArgumentType, int, vector<int>> ParamType;

class LeetCode27Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode27Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode27::Solution();
  ArgumentType arguments;
  int len;
  vector<int> asserts;
  tie(arguments, len, asserts) = GetParam();

  vector<int> nums = get<0>(arguments);  // 取出函数的参数
  int val = get<1>(arguments);

  ASSERT_EQ(solution->removeElement(nums, val), len);  // 断言结果
  vector<int> slice(nums.begin(), nums.begin() + len);
  // ::vector_print(nums);
  ASSERT_TRUE(::vector_unordered_cmp(slice, asserts));  // 断言返回的结果
}

vector<int> p1_0{3, 2, 2, 3};
ArgumentType p1(p1_0, 3);  // 参数1

vector<int> p2_0{0, 1, 2, 2, 3, 0, 4, 2};
ArgumentType p2(p2_0, 2);  // 参数2

vector<int> p3_0{2};
ArgumentType p3(p3_0, 3);  // 参数3

vector<int> r1{2, 2};
vector<int> r2{0, 1, 3, 0, 4};
vector<int> r3{2};

auto values = ::testing::Values(
  ParamType(p1, r1.size(), r1),
  ParamType(p2, r2.size(), r2),
  ParamType(p3, r3.size(), r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode27ParamTest, LeetCode27Test, values);

}