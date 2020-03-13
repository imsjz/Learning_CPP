// Copyright 2020 Sanjay Zhong
#include <iostream>
#include <vector>

using namespace std;

// 1. 委托构造
class Base{
  public:
    int value1_;
    int value2_;
    Base() {
      value1_ = 1;
    }
    Base(int value) : Base() {  // 委托Base()构造函数
      value2_ = 2;
    }
};

// 2. 继承构造
class Subclass : public Base {
public:
  using Base::Base;
};

// 3. 显式虚函数重载--使用override 和 final来实现和避免
// 4. 显式禁用默认函数--使用delete

//#########################
// 强枚举类型


int main(int argc, char* argv[]) {
//   Base b(2);
//   cout << b.value1_ << " " << b.value2_ << endl;
  Subclass s(2);
  cout << s.value1_ << " " << s.value2_ << endl;

  return 0;
}
