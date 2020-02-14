// Copyright 2020 Sanjay Zhong
#include <iostream>
#include <vector>

using namespace std;

namespace sanjay1{
  class Test{
   public:
    inline static int a = 6;  //c++17才有
    // static int b = 7;  // 直接static是不能在类内初始化的
    const static int c = 8; // 这样也可以
  };
}

namespace sanjay2{
  class Test{
   public:
    void func(){
      cout << "non-const func" << endl;
    }
    void func() const {
      cout << "const func" << endl;
    }
    void another(){
      cout << "another" << endl;
    }
  };
  void test(){
    Test t;
    t.func(); //带const和不带const的可以重载
    const Test t2;
    t2.func();
    // t2.another(); //error
  }
}

#include <unistd.h>
namespace sanjay3
{
  void test_const() {
    const int a = 20;
    int* b = const_cast<int*>(&a);
    *b = 30;
    cout << *b << endl;
  }
} // namespace sanjay3

namespace sanjay4
{
  typedef int& lref;
  typedef int&& rref;
  void test() {
    int n = 10;
    lref& r1 = n; // type of r1 is int&
    lref&& r2 = n;  // int&
    rref& r3 = n; // int&
    rref&& r4 = 20;  // int&&
  }

} // namespace sanjay4

namespace sanjay5
{
  template <typename T>
  void f(T&& t) {
    cout << typeid(t).name() << endl;
    cout << &t << endl;
  }
  void test() {
    int i = 0;
    f(i);
    f(0);
  }
} // namespace sanjay5



int main(int argc, char* argv[]) {
  // sanjay1::Test t;
  // cout << t.a << endl;
  // sanjay2::test();
  // sanjay3::test_const();
  sanjay5::test();
  return 0;
}
