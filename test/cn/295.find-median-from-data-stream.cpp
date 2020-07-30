//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "295.find-median-from-data-stream.h"

namespace LeetCode295 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode295Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode295Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  MedianFinder* finder;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    // cout << actions[i] << endl;
    if (actions[i] == "MedianFinder") {
      finder = new MedianFinder();
      os << "null,";
    } else if (actions[i] == "addNum") {
      finder->addNum(inputs[i][0]);
      os << "null,";
    } else if (actions[i] == "findMedian") {
      // 使用 setprecision 设置精度，不能使用 to_string, to_string 默认精确到6位
      os << std::setprecision(5) << std::fixed << finder->findMedian() << ",";
    }
  }

  string asserted = os.str();
  ASSERT_EQ(asserted.substr(0, asserted.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"MedianFinder","addNum","addNum","findMedian","addNum","findMedian"},
                         {{},{1},{2},{},{3},{}}),
            "null,null,null,1.50000,null,2.00000"),
  ParamType(ArgumentType({"MedianFinder","addNum","findMedian","addNum","findMedian"},
                         {{},{2},{},{3},{}}),
            "null,null,2.00000,null,2.50000")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode295ParamTest, LeetCode295Test, values);

}