//
// Created by timking.nf@foxmail.com on 2021/3/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_17_11.find-closest-lcci.h"

namespace LeetCode_17_11 {

typedef tuple<vector<string>, string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_17_11Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_17_11Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_17_11::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> words;
  string word1, word2;
  tie(words, word1, word2) = arguments;

  ASSERT_EQ(solution->findClosest(words, word1, word2), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"I","am","a","student","from","a","university","in","a","city"},
                         "a", "student"), 1),
  ParamType(ArgumentType({"1","3","3","3","2","3","1"}, "1", "2"), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_17_11ParamTest, LeetCode_17_11Test, values);

}