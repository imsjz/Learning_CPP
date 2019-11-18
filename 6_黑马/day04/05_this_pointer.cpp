/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-12 09:33:07
 */
#include <iostream>

using namespace std;

class Person{
public:
    Person(int age){
        this->age = age;
    }
    Person& PlusAge(Person &p){
        this->age += p.age;
        return *this;
    }
    int age;
};

void test01(){

    Person p1(10);

    cout << "p1的年龄 " << p1.age << endl;

    Person p2(20);

    p1.PlusAge(p2).PlusAge(p2);

    cout << "p1的年龄 " << p1.age << endl;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
