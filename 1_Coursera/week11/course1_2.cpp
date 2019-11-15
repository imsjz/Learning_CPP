/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 16:54:13
 */
#include <iostream>
#include <memory>
using namespace std;
struct A{
    ~A(){ cout << "~A" << endl;}
};

int main(){
    A *p = new A;
    shared_ptr<A> ptr1(p);
    shared_ptr<A> ptr2;
    ptr2.reset(p);
    cout << "end" << endl;
    return 0;
}