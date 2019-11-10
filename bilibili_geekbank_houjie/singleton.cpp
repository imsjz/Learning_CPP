/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-10 13:24:30
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class A{
public:
    static A& getInstance(); //静态成员函数, 没有this pointer
    
private:
    A();
    A(const A& rhs);
};

A& A::getInstance(){
    static A a;
    return a;
}

void test01(){
    
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
