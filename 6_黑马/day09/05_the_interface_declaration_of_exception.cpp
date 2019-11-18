/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 22:42:33
 */
#include <iostream>

using namespace std;

//dynamic exception specifications are deprecated in C++11
// void func() throw(int) { //throw(int) 只能抛出int类型异常  
void func() throw() {        //throw() 表示不抛出任何异常
    throw 1.1;
}

int main(int argc, char *argv[]){
    try{
        func();
    }
    catch(int){
        cout << "int类型异常捕获" << endl;
    }
    catch(...){
        cout << "其他类型" << endl;
    }

    return 0;
}
