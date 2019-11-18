/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 21:57:20
 */
#include <iostream>

using namespace std;

class Base{
public:

    static void func(){
        cout << "base func()" << endl;
    }

    static void func(int a){
        cout << "base func(int a)" << endl;
    }

    static int a_;
};

int Base::a_ = 10;

class Son : public Base{
public:
    static void func(){
        cout << "son func()" << endl;
    }

    static int a_;
};
int Son::a_ = 20;

void test01(){
    //静态成员,子类可以继承下来
    cout << Son::a_ << endl;
    cout << "父类: " << Base::a_ << endl;

    Son::func();

    Son::Base::func();
    Son::Base::func(10);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
