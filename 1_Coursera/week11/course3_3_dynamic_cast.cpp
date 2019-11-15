/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 15:56:35
 */
#include <iostream>
#include <string>
using namespace std;
class Base{
    //有虚函数，因此是多态基类
    public:
        virtual ~Base(){}
};
class Derived:public Base{};
int main(){
    Base b;
    Derived d;
    Derived *pd;
    pd = reinterpret_cast<Derived*>(&b);
    if(pd == NULL)
        cout << "unsafe reinterpret_cast" << endl;
    pd = dynamic_cast<Derived*>(&b);
    if(pd == NULL)
        cout << "unsafe dynamic_cast1" << endl;
    Base *pb = &d; //基类指针指向派生类
    pd = dynamic_cast<Derived*>(pb); //安全的转换
    if(pd == NULL)
        cout << "unsafe dynamic_cast2" << endl;

    return 0;
}