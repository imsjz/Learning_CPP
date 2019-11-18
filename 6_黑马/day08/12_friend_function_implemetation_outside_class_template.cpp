/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 11:16:22
 */
#include <iostream>
#include <string>

using namespace std;

//让编译器提前看到PrintPerson的声明

//让编译器看到Person类声明
template<class T1, class T2> class Person;
template<class T1, class T2> void PrintPerson (Person<T1, T2> &p); //这里声明不用空参数列表


template<class T1, class T2>
class Person{

   
    // friend void PrintPeron(const Person<T1, T2> &p); //这个是普通函数, 因为没有紧跟着template
    //利用空参数列表告诉编译器, 这是函数模板的声明
    friend void PrintPerson<> (Person<T1, T2> &p);  //函数类内部声明,一开始编译器看不到
    //     cout << "姓名: " << p.name_ << " 年龄: " << p.age_ << endl;
    // }
public:
    Person(T1 name, T2 age){
        this->name_ = name;
        this->age_ = age;
    }

private:
    T1 name_;
    T2 age_;
};


template<class T1, class T2>
void PrintPerson(Person<T1, T2> &p){
    cout << "姓名: " << p.name_ << " 年龄: " << p.age_ << endl;
}

void test01(){
    Person<string, int> p("tom", 19);
    PrintPerson(p);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
