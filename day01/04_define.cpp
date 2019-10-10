/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 16:29:44
 */
#include <iostream>

using namespace std;

#define PARAM 128 //无类型，默认为int

const short param = 20;

void func(short a){
    cout << "short " << endl;
}
void func(int a){
    cout << "int " << endl;
}

//2. 宏常量不重视作用域
void func1(){
    const int a = 10;
    #define A 20

    //卸载宏常量A
    #undef A
}

void func2(){

    //cout << "a: " << a << endl; //访问不到a
    //cout << "A: " << A << endl;
}

//3.宏常量没有命名空间
namespace myspace{
    #define num 1024
}

void test(){
    //cout << myspace::num << endl; //err

    //int num = 100; //命名冲突

    cout << num << endl;
}

int main(int argc, char *argv[]){
    // func(PARAM);
    // func(param);

    func2();
    test();

    return 0;
}
