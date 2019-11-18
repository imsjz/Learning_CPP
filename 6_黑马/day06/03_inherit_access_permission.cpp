/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 15:59:43
 */
#include <iostream>

using namespace std;

class Base{
public:
    int a_;
protected:
    int b_;
private:
    int c_;
};

//公有继承
class SonPublic: public Base{
public:
    void func(){
        // cout << c_ << endl; //基类中私有的属性　不可继承
        cout << a_ << endl;
        cout << b_ << endl;
    }
};



////////////////////保护继承///////////////////

class SonProtected: protected Base{
public:
    void func(){
        // cout << c_ << endl; //基类中私有的属性　不可继承
        cout << a_ << endl;    //基类中的公有属性　可继承，　为protected
        cout << b_ << endl;    //基类中的保护属性　可继承，　为protected
    }
};



////////////////////私有继承///////////////////

class SonPrivate: private Base{
public:
    void func(){
        // cout << c_ << endl; //基类中私有的属性　不可继承
        cout << a_ << endl;    //基类中的公有属性　可继承，　为private
        cout << b_ << endl;    //基类中的保护属性　可继承，　为private
    }
};

//测试上面
class GrandSon: public SonPrivate{
public:
    void GrandFunc(){
        // cout << a_ << endl; //孙子类中访问不到a_, 因为在前面的类中已经为私有属性了
    }
};


void test01(){

    SonPublic son_public;
    son_public.func();

    SonProtected son_protected;
    // son_protected.a_; //保护类型，类外不能访问
    son_protected.func();

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
