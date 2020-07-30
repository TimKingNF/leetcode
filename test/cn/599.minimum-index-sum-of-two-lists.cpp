//
// Created by timking.nf@foxmail.com on 2020/7/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "599.minimum-index-sum-of-two-lists.h"

namespace LeetCode599 {

typedef tuple<vector<string>, vector<string>> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode599Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode599Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode599::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> list1, list2;
  tie(list1, list2) = arguments;

  ASSERT_EQ(solution->findRestaurant(list1, list2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"Shogun", "Tapioca Express", "Burger King", "KFC"},
                         {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}),
            {"Shogun"}),
  ParamType(ArgumentType({"Shogun", "Tapioca Express", "Burger King", "KFC"},
                         {"KFC", "Shogun", "Burger King"}),
            {"Shogun"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode599ParamTest, LeetCode599Test, values);

}