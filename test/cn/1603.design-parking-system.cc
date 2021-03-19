//
// Created by timking.nf@foxmail.com on 2021/3/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1603.design-parking-system.h"

namespace LeetCode1603 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1603Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1603Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<string> actions;
  vector<vector<int>> inputs;
  tie(actions, inputs) = arguments;
  ParkingSystem* system;
  ostringstream os;

  for (int i = 0; i < actions.size(); ++i) {
    if (actions[i] == "ParkingSystem") {
      system = new ParkingSystem(inputs[i][0], inputs[i][1], inputs[i][2]);
      os << "null,";
    } else if (actions[i] == "addCar") {
      os << (system->addCar(inputs[i][0]) ? "true" : "false") << ",";
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"ParkingSystem", "addCar", "addCar", "addCar", "addCar"},
                         {{1, 1, 0}, {1}, {2}, {3}, {1}}),
            "null,true,true,false,false")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1603ParamTest, LeetCode1603Test, values);

}