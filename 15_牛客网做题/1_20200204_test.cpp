#include <iostream>
#include <vector>

using namespace std;

void test1(){
    //内置类型初始化问题
    int *p1 = new int[10]; //仅分配内存，没有初始化
    int *p2 = new int[10](); //分配内存同时初始化

    for(int i = 0; i < 10; ++i){
        cout << *(p1 + i) << " ";
    }
    cout << endl;

    for(int i = 0; i < 10; ++i){
        cout << *(p2 + i) << " ";
    }
    cout << endl;

}

//函数外定义
//枚举变量是全局变量的情况下， 枚举值的缺省值是0，不是枚举的第一个值。
enum string{    
    x1,    
    x2,    
    x3=10,    
    x4,    
    x5,    
} x;

void test2(){
    //如果枚举变量在函数内定义，则未初始化
    enum string{    
    x1,    
    x2,    
    x3=10,    
    x4,    
    x5,    
} x_in;
    cout << x << endl;
    cout << x_in << endl;
}

int main(int argc, char* argv[]){
    // test1();
    test2();
    return 0;
}
