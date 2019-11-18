/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 12:32:24
 */
#include <iostream>
#include <cstring>

using namespace std;

//一个类默认创建：　默认构造、析构、拷贝构造、operator=赋值运算符　　进行简单的值传递
class Person{
public:
    Person(int a):a_(a){}

    int a_;
};

class Person2{
public:
    Person2(char *name){
        this->p_name_ = new char[strlen(name) + 1];
        strcpy(this->p_name_, name);
    }

    ~Person2(){
        if(this->p_name_ != NULL){
            cout << "析构" << endl;
            delete [] this->p_name_;
            this->p_name_ = NULL;
        }
    }

    //重载＝赋值运算符
    Person2& operator=(const Person2 &p){
        //如果this原来堆区有内容，先释放
        if(this->p_name_ != NULL){
            delete [] this->p_name_;
        }
        this->p_name_ = new char[strlen(p.p_name_) + 1];
        strcpy(this->p_name_, p.p_name_);

        return *this;
    }

    char *p_name_;
};

void test01(){

    Person p1(10);
    Person p2(0);

    p2 = p1; //赋值

    cout << "p2的ａ_ "  << p2.a_ << endl;

}

void test02(){

    Person2 p1("狗蛋");
    Person2 p2("狗剩");

    Person2 p3("");
    p3 = p2 = p1;   //浅拷贝会出现问题

    cout << "p2 name: " << p2.p_name_ << endl;
    cout << "p3 name " << p3.p_name_ << endl;
}
int main(int argc, char *argv[]){
    // test01();
    test02();

    int a = 10;
    int b = 20;
    int c;
    c = a = b;
    cout << "c = " << c << " " << b << " " << c << endl;

    return 0;
}
