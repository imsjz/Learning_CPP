// Copyright 2020 Sanjay Zhong
#include <iostream>
#include <vector>

using namespace std;

// 1. lambda表达式
// 1.1 值捕获
void learn_lambda_func_1() {
  int value_1 = 1;
  auto copy_value_1 = [value_1] {
    return value_1; // 1
  };

  // 2.2 引用捕获
  auto referenced_value_1 = [&value_1] {
    return value_1;
  };

  value_1 = 100;
  auto stored_value_1 = copy_value_1();
  auto stored_rvalue_1 = referenced_value_1();
  cout << "value_1 = " << value_1 << endl;
  cout << "stored_value_1 = " << stored_value_1 << endl;
  cout << "stored_rvalue_1 = " << stored_rvalue_1 << endl;  // 100
}

// 3. 隐式捕获 =代表值捕获，&代表引用捕获


//#################
// 函数对象包装器 std::function
using foo = void(int); // 函数指针
void functional(foo f) {
  f(1);
}

int bar(int para) {
  return para;
}

void std_function() {
  std::function<int(int)> func1 = bar;
  int importance = 10;
  function<int(int)> func2 = [&](int value) -> int {
    return 1 + value + importance;
  };
  cout << func1(10) << endl; // 10
  cout << func2(20) << endl;  // 1 + 20 + 10 = 31
}


int main(int argc, char* argv[]) {
  // learn_lambda_func_1();
  // auto f = [](int value) {
  //   cout << value << endl;
  // };
  // functional(f);
  // f(1);
  std_function();
  return 0;
}
