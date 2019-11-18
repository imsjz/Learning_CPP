/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-13 10:20:24
 */
#include <iostream>

using namespace std;

class Person{

public:
    Person(){}
    Person(int a, int b):a_(a), b_(b){}
    // void operator<<(){ 重载左移运算符不可以写到成员函数中

    // }
    friend ostream& operator<<(ostream &cout, const Person &person);
private:
    int a_;
    int b_;
};

// cout << p1         第一个参数是cout   运算符是<<  第二个参数是p1
//因为cout带缓冲区，因此要用&把之前的接进来
ostream& operator<<(ostream &cout, const Person &person){
    cout << "a_ " << person.a_ << " b_ " << person.b_;
    return cout;
}

void test01(){

    Person p1(10,10);
    // cout << p1 << endl;
    // p1 << ...
    // cout << endl;
    cout << p1 << endl;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
