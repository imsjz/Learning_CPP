/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-13 20:03:20
 */
#include <iostream>
using namespace std;
class A {
// 在此处补充你的代码
public:
    virtual ~A() { cout << "destructor A" << endl;}
};
class B:public A {
    public:
        ~B() { cout << "destructor B" << endl; }
};
int main() {
    A * pa; //声明一个A类的指针
    pa = new B; //申请一个B类对象，并将此指针赋给pa
    delete pa;
    return 0;
}