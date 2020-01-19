#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
   
   int num = 1234;
   string str_num = to_string(num);
   cout << typeid(num).name() << endl;
   cout << typeid(str_num).name() << endl;
   char a = 1 + '0';
   cout << a << endl;
   int b = 2;
   num += 2 + 1;
   cout << num << endl;
   return 0;
}
