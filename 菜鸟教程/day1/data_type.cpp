#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(){

  //cpp有七种基本的数据类型：
  bool b;
  char c;
  int i;
  float f;
  double d;
  //void none;
  wchar_t w;
  //wchar_t是这样来的:
  //typedef short int wchar_t;
  

  cout << "type: \t\t" << "*****************size******************" << endl;
  cout << "bool: \t\t\t\t" << "字节数：" << sizeof(bool) << endl;
  cout << "char: \t\t\t\t" << "字节数：" << sizeof(char) << endl;
  cout << "signed char: \t\t\t" << "字节数: " << sizeof(signed char) << endl;
  cout << "unsigned char: \t\t\t" << "字节数：" << sizeof(unsigned char) << endl;
  cout << "wchar_t: \t\t\t" << "字节数：" << sizeof(wchar_t) << endl;
  cout << "short: \t\t\t\t" << "字节数: " << sizeof(short) << endl;
  cout << "int: \t\t\t\t" << "字节数：" << sizeof(int) << endl;
  cout << "unsigned: \t\t\t" << "字节数：" << sizeof(unsigned) << endl;
  cout << "long: \t\t\t\t" << "字节数: " << sizeof(long) << endl;
  cout << "unsigned long: \t\t\t" << "字节数：" << sizeof(unsigned long) << endl;
  cout << "float: \t\t\t\t" << "字节数：" << sizeof(float) << endl;
  cout << "size_t(long unsigned int): \t" << "字节数: " << sizeof(size_t) << endl;
  cout << "string: \t\t\t" << "字节数: " << sizeof(string) << endl;


  return 0;


}

