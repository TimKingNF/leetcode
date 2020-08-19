//
// Created by timking.nf@foxmail.com on 2020/8/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "648.replace-words.h"

namespace LeetCode648 {

typedef tuple<vector<string>, string> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode648Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode648Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode648::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> dict;
  string sentence;
  tie(dict, sentence) = arguments;

  ASSERT_EQ(solution->replaceWords(dict, sentence), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"cat", "bat", "rat"},
                         "the cattle was rattled by the battery"),
            "the cat was rat by the bat")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode648ParamTest, LeetCode648Test, values);

}