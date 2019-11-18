/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 10:38:44
 */
#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age);

    void ShowPerson();

    T1 name_;
    T2 age_;
};


template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){

    this->name_ = name;
    this->age_ = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson(){

    cout << "姓名: " << this->name_ << " 年龄:  " << this->age_ << endl;
}