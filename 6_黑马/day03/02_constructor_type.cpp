/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 15:42:39
 */
#include <iostream>

using namespace std;

class Person{
public:
    //无参构造函数
    Person(){
        cout << "默认构造函数" << endl;
    }

    //有参构造函数
    Person(int a){
        cout << "有参构造函数" << endl;
    }

    //拷贝构造函数
    Person(const Person &a){
        cout << "拷贝构造函数" << endl;
    }

    ~Person(){
        cout << "析构函数" << endl;
    }
    int m_Age;

};

void test01(){

    // //构造函数的调用方法
    // //1. 括号法
    // Person p1(1); //有参
    // p1.m_Age = 10;
    // Person p2(p1); //拷贝

    //默认构造函数
    //Person p3(); //会认为是函数声明
    //Person p3;

#if 0
    //2. 显式调用
    Person p4 = Person(100);
    Person p5 = Person(p4); //拷贝构造函数
    cout << "--------------" << endl;
    // Person(100); //匿名对象,如果编译器发现了对象是匿名的，那么在这行代码结束后就释放这个对象
    // cout << "aaa" << endl;
    //不能用拷贝函数初始化匿名对象
    //Person(p5); //写成左值，这样写编译器会认为你写成了Person p5;(对象声明)报重定义的错误；
    //写成右值可以
    Person p6 = Person(p5);
    
#endif

    Person p7 = 100; //有参构造函数，相当于调用了Person p7 = Person(100)，隐式类型转换
    Person p8 = p7; //相当于Person p8 = Person(p7); 拷贝构造函数

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
