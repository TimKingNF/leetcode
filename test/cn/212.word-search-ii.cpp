//
// Created by timking.nf@foxmail.com on 2020/8/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "212.word-search-ii.h"

namespace LeetCode212 {

typedef tuple<vector<vector<char>>, vector<string>> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode212Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode212Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode212::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<char>> board;
  vector<string> words;
  tie(board, words) = arguments;

  ASSERT_EQ(solution->findWords(board, words), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{'o','a','a','n'},
                          {'e','t','a','e'},
                          {'i','h','k','r'},
                          {'i','f','l','v'}},
                         {"oath","pea","eat","rain"}),
            {"eat", "oath"}),
  ParamType(ArgumentType({{'a', 'a'}},
                         {"a"}),
            {"a"}),
  ParamType(ArgumentType({{'a', 'b'},
                          {'a', 'a'}},
                         {"aba","baa","bab","aaab","aaa","aaaa","aaba"}),
            {"aaa","aaab","aaba","aba","baa"}),
  ParamType(ArgumentType({{'a','b','c'},
                          {'a','e','d'},
                          {'a','f','g'}},
                        {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"}),
            {"abcdefg","befa","eaabcdgfa","gfedcbaaa"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode212ParamTest, LeetCode212Test, values);

}
