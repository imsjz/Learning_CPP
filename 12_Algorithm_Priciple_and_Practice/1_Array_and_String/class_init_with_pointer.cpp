/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-16 10:34:35
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
//############################################//
//################   测试一下带有指针的类的初始化问题   ####################//
//############################################//
class Base{
public:
    int a;
    float b;
    double c;
    Base* next;
    void print(){
        cout << "print" << endl;
    }
    void get(){
        cout << this->a << endl;
    }

};
void test01(){
    //############################################//
    //################   类内普通成员变量不会自动初始化, 给的是随机值   ####################//
    //############################################//
    Base b;
    cout << b.a << endl;
    cout << b.b << endl;
    cout << b.c << endl;
    cout << b.next << endl;
    Base* c = b.next;
    c->a;

    cout << "=============================" << endl << endl;
    //############################################//
    //################   用new来试试: new会自动将值初始化   ####################//
    //############################################//
    Base* new_b = new Base;
    cout << new_b->a << endl;
    cout << new_b->b << endl;
    cout << new_b->c << endl;
    cout << new_b->next << endl;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
