/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 21:16:32
 */
#include <iostream>

using namespace std;


class Person1{
public:
    void show_person1(){
        cout << "person1 的调用" << endl;
    }
};

class Person2{
public:
    void show_person2(){
        cout << "person2 的调用" << endl;
    }
};

template<class T>
class MyClass{
public:
    T obj;
    void func1(){
        obj.show_person1();
    }
    void func2(){
        obj.show_person2();
    }
};

//成员函数 一开始不会创建出来, 而是在运行时才去创建

void test01(){
    MyClass<Person1> my_class;
    my_class.func1();
    // my_class.func2(); //error

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
