// Copyright 2020 Sanjay Zhong
#include <iostream>
#include <vector>

using namespace std;

void test() {
  int arr1[10];  // 值不确定
  int* p1 = new int[10];  // 仅分配内存，没有初始化
  int* p2 = new int[10]();  //会进行值初始化
  int arr2[5]{1,2};
  for (auto ele : arr2) {
    cout << ele << " ";
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  test();
  return 0;
}
