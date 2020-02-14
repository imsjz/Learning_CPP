// Copyright 2020 Sanjay Zhong
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int a, *b = &a, &c = a;
  decltype(a) d;  // d的类型是int
  decltype((a)) e = a;  //(a)是表达式，是一个lvalue，因此decltype会推导为引用类型，这样e一定要绑定某个值
  decltype(*b) f = a; //同样，*b也是表达式，是lvalue
  decltype(c) g = a;  //int&
  decltype(a+0) h;  //int
  return 0;
}
