//
// Created by timking.nf@foxmail.com on 2020/11/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "127.word-ladder.h"

namespace LeetCode127 {

typedef tuple<string, string, vector<string>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode127Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode127Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode127::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string beginWord, endWord;
  vector<string> wordList;
  tie(beginWord, endWord, wordList) = arguments;

  ASSERT_EQ(solution->ladderLength(beginWord, endWord, wordList), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("hit", "cog", {"hot","dot","dog","lot","log","cog"}), 5),
  ParamType(ArgumentType("hit", "cog", {"hot","dot","dog","lot","log"}), 0),
  ParamType(ArgumentType("qa", "sq",
                         {"si","go","se","cm","so","ph","mt","db","mb",
                          "sb","kr","ln","tm","le","av","sm","ar","ci","ca",
                          "br","ti","ba","to","ra","fa","yo","ow","sn","ya",
                          "cr","po","fe","ho","ma","re","or","rn","au","ur",
                          "rh","sr","tc","lt","lo","as","fr","nb","yb","if",
                          "pb","ge","th","pm","rb","sh","co","ga","li","ha",
                          "hz","no","bi","di","hi","qa","pi","os","uh","wm",
                          "an","me","mo","na","la","st","er","sc","ne","mn",
                          "mi","am","ex","pt","io","be","fm","ta","tb","ni",
                          "mr","pa","he","lr","sq","ye"}), 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode127ParamTest, LeetCode127Test, values);

}