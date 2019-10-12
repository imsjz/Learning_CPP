/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 14:20:15
 */
#include <iostream>

using namespace std;

class Person{
public:
    Person(){
        //m_Age = 10;
    }

    static int m_Age; //加入static就是静态成员变量, 会共享数据
    //静态成员变量,在类内声明,类外进行初始化

    //静态成员函数
    //不能访问普通成员变量
    int m_A;
    static void func(){
        cout << "func调用" << endl;
        //m_A = 10;
        m_Age = 20;
    }

    //普通成员函数可以访问普通成员变量,也可以访问静态成员变量
    void myFunc(){
        m_Age  = 100;
        m_A = 200;
    }
    //const静态成员
    const static int m_const_static = 300;
private:

    //静态成员函数也是有属性的
    static void func1(){
        cout << "私有 静态成员函数" << endl;
    }
    static string name;
};

int Person::m_Age = 0;//类外实现初始化
string Person::name = "hell";
void test01(){

    //1.通过对象访问属性
    Person p1;
    p1.m_Age = 10;
    cout << "const static " << p1.m_const_static << endl;
    //p1.m_const_static = 20;

    Person p2;
    p2.m_Age = 20;

    cout << "p1 age = " << p1.m_Age << endl;
    cout << "p2 age = " << p2.m_Age << endl; //共享数据,都是20
    p1.myFunc(); //m_Age = 100;

    //2.通过类名访问属性
    cout << "通过类名访问 " << Person::m_Age << endl;


    p1.func();
    Person::func();
    //Person::func1();

}


int main(int argc, char *argv[]){
    test01();

    return 0;
}
