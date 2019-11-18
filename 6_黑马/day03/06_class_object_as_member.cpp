/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 11:14:03
 */
#include <iostream>

using namespace std;

class Phone{
public:
    Phone(){
        cout << "手机的默认构造函数调用" << endl;
    }
    Phone(string name):m_PhoneName(name){
        cout << "手机的 有参构造函数" << endl;
    }
    ~Phone(){
        cout << "手机的    析构函数" << endl;
    }
    string m_PhoneName;
};

class Person{
public:


    Person(){
        cout << "person 的默认构造" << endl;
    }
    Person(string name, string phoneName):m_Name(name), m_Phone(phoneName){
        cout << "person 的有参构造函数"  << endl;
    }
    ~Person(){
        cout << "person 的析构函数 "  << endl;
    }


    string m_Name;
    Phone m_Phone;
};

void test01(){

    // Person p("张三", "苹果");
    Person p;
    //p.m_Phone.m_PhoneName = "三星";

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
