/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-20 11:00:49
 */
#include <iostream>
#include <string>
#include <stdexcept> //系统提供的标准异常 要包含头文件

using namespace std;

class Person{
public:

    Person(string name, int age){
        this->name_ = name;

        if(age < 0 || age > 200){
            //抛出越界异常
            // throw out_of_range("年龄越界了");

            throw length_error("长度越界了");
        }
        this->age_ = age;
    }

    string name_;
    int age_;
};

void test01(){
    try{
        Person p("张三", 1000);
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }
    catch(length_error &e){
        cout << e.what() << endl;
    }
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
