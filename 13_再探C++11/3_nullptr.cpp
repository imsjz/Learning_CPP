/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-27 21:50:05
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:

};

void foo(char*){
    cout << "call foo(char*)" << endl;
}

void foo(int){
    cout << "call foo(int)" << endl;
}

void test01(){
    if(NULL == (void*)0){
        cout << "NULL = 0" <<endl;
    }
    else
        cout << "NULL != 0" << endl;

    foo(0); //int
    // foo(NULL);
    foo(nullptr); //char*
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
