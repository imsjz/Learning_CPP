/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-20 12:02:58
 */
#include <iostream>
#include <stdexcept>

using namespace std;

class MyOutOfRangeException : public exception{
public:

    MyOutOfRangeException(string error_info){
        this->error_info_ = error_info;
    }
    //需要重载虚析构函数
    virtual ~MyOutOfRangeException(){
        
    }

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */

    //和重载what()函数
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT{
        //返回错误信息
        //string 转 const char
        return this->error_info_.c_str();
    }
    string error_info_;
};

class Person{
public:

    Person(string name, int age){
        this->name_ = name;

        if(age < 0 || age > 200){
            //抛出越界异常
            throw MyOutOfRangeException(string("我自己的年龄越界异常"));
        }
        this->age_ = age;
    }

    string name_;
    int age_;
};


void test01(){
    try{
        Person p("张三", 2000);
    }
    catch(MyOutOfRangeException &e){
        cout << e.what() << endl;
    }
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
