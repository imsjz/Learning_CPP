/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-16 12:23:46
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class A{
public:
    virtual void vfunc1(){
        cout << "A" << endl;
    }
};

class B: public A{
public:
    virtual void vfunc1(){
        cout << "B" << endl;
    }
};
int main(int argc, char *argv[]){
    B b;
    A a = (A)b;
    a.vfunc1();

    A* pa = new B;
    pa->vfunc1();

    pa = &b;
    pa->vfunc1();

    return 0;
}
