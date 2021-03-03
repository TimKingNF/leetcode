//
// Created by timking.nf@foxmail.com on 2021/3/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "304.range-sum-query-2d-immutable.h"

namespace LeetCode304 {

typedef vector<vector<int>> MatrixType;
typedef vector<vector<int>> ArgT;
typedef tuple<vector<string>, MatrixType, ArgT> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode304Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode304Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> actions;
  MatrixType initials;
  ArgT args;
  tie(actions, initials, args) = arguments;

  NumMatrix* numMatrix;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "NumMatrix") {
      numMatrix = new NumMatrix(initials);
      os << "null,";
    } else if (actions[i] == "sumRegion") {
      os << numMatrix->sumRegion(args[i-1][0], args[i-1][1], args[i-1][2], args[i-1][3]) << ",";
    }
  }
  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"NumMatrix","sumRegion","sumRegion","sumRegion"},
                                {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}},
                                {{2,1,4,3},{1,1,2,2},{1,2,2,4}}),
            "null,8,11,12")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode304ParamTest, LeetCode304Test, values);

}