#include <iostream>

using namespace std;

int main(){
    int var1;
    char var2[10];

    cout << "var1 address: ";
    cout << &var1 << endl;


    cout << "var2 address: ";
    cout << &var2 << endl;

    // what if &var2+1

    cout << "&var2+1: ";
    cout << &var2 + 1 << endl;
    //这里直接加了10个地址，因为直接&var2取到的是整个数组的地址，然后
    //要注意的是，内存中的地址都是以字节来编码的，也就是说，一个地址里有8位

    return 0;

}
