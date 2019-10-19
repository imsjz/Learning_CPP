/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 10:29:02
 */
#include <iostream>

using namespace std;


template<class T1, class T2>
class Person{
public:

    Person(T1 name, T2 age);

    void ShowAge();

    T1 name_;
    T2 age_;
};

//类外实现成员函数
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->name_ = name;
    this->age_ = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowAge(){
    cout << this->age_ << endl;
}


void test01(){
    Person<string, int> p1("张三", 20);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
