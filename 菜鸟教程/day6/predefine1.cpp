#include <iostream>
using namespace std;

#define MKSTR(x) #x

int main(){
    //会将hello c++ 变成字符串
    cout << MKSTR(hello c++) << endl;
    return 0;
}
