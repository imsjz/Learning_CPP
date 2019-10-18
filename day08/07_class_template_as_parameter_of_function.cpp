/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 21:23:16
 */
#include <iostream>
#include <string>

using namespace std;

//类模板
template<class NameType, class AgeType  = int> //类模板可以有默认类型
class Person{
public:
    Person(NameType name, AgeType age){
        name_ = name;
        age_ = age;
    }
    void ShowAge(){
        cout << "姓名: " << this->name_ << " 年龄: " << this->age_ << endl;
    }

    NameType name_;
    AgeType age_;
};

//1.指定传入类型
void DoWork(Person<string, int> &p){
    p.ShowAge();
}

//2.参数模板化
template<class T1, class T2>
void DoWork2(Person<T1, T2> &p){
    p.ShowAge();
    //查看调用类型
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
}

void test01(){
    Person<string, int> p("孙悟空", 23);
    DoWork(p);
    DoWork2(p);
}

//3. 整体模板化
template<class T>
void DoWork3(T &p){
    p.ShowAge();
    cout << typeid(p).name() << endl;
}

void test03(){
    Person<string, int> p("略人", 23);
    DoWork3(p);
}

int main(int argc, char *argv[]){
    test01();
    test03();


    return 0;
}
