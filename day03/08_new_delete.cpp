/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 12:38:21
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

void test01(){

    Person* p = new Person;//堆区开辟
    //所有new出来的对象,都会返回该类型的指针
    //malloc不会调用构造函数,new会
    //new是运算符, malloc是函数
    //delete也是运算符
    delete p;

    //用void*接受,释放有问题
    void *p1 = new Person;
    delete p1; //无法调用析构函数

}

void test02(){
    //通过new开辟数组
    //可以通过堆区初始化,这时候调用有参构造
    Person *pArray = new Person[10]{1,2,3,4,5,6,7,8,9,0};

    cout << "---------------------------------============================" << endl;
    Person pArray1[4] = {Person(1), Person(2)};//前面两个是有参,后面无参则用默认构造函数

    //释放数组要加[]
    delete [] pArray;

}
int main(int argc, char *argv[]){
    //test01();
    test02();

    return 0;
}
