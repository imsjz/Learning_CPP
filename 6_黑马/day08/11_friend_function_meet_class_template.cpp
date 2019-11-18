/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 11:16:22
 */
#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person{

    //友元函数类内实现
    friend void PrintPerson(const Person<T1, T2> &p){
        cout << "姓名: " << p.name_ << " 年龄: " << p.age_ << endl;
    }
public:
    Person(T1 name, T2 age){
        this->name_ = name;
        this->age_ = age;
    }

private:
    T1 name_;
    T2 age_;
};

void test01(){
    Person<string, int> p("tom", 19);
    PrintPerson(p);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
