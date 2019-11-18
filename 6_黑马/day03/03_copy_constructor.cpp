/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 16:21:17
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
    Person(const Person &a){ //如果没有&，那么会新分配内存给临时变量，创建Person，需要用到拷贝构造函数，进而无限循环
        cout << "拷贝构造函数" << endl;
    }

    ~Person(){
        cout << "析构函数" << endl;
    }
    int m_Age;

};


//拷贝构造函数的调用时机
//1. 用已经创建好的对象来初始化新的对象
void test01(){

    Person p1;
    p1.m_Age = 20;

    Person p2(p1);

}

//2.以值传递的方式给函数参数传值
void doWork(Person p){

}
void test02(){

    Person p1;

    doWork(p1);
}


////////////////////////重点，编译器会做优化￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥
//3. 以值的方式返回局部对象
Person doWork2(){
    Person p1(1);
    p1.m_Age = 20;

    return p1;
}
void test03(){

    Person p = doWork2();
    cout << "cool" << endl;
}
int main(int argc, char *argv[]){
    //test01();
    //test02();

    test03();

    return 0;
}
