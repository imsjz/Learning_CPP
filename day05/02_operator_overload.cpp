/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-12 14:12:27
 */
#include <iostream>

using namespace std;

class Person{

public:
    Person(){}
    Person(int a, int b):a_(a), b_(b){}
    Person operator+(const Person &p);
    int a_;
    int b_;
};

Person Person::operator+(const Person &p){
    Person tmp;
    tmp.a_ = this->a_ + p.a_;
    tmp.b_ = this->b_ + p.b_;
    return tmp;
}


void test01(){

    Person p1(10, 10);
    Person p2(20, 30);
    Person p3 = p1 + p2; //==> p1.operator+(p2)  或者 operator+(p1, p2);

    cout << "p3 " << p3.a_ << " " << p3.b_ << endl;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
