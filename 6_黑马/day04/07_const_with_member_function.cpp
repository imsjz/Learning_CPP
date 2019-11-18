/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-12 10:25:31
 */
#include <iostream>

using namespace std;

class Person{
public:
    Person(){

        //this永远指向本体  this --->    Person * const this;
        //想要属性不能用this更改, const Person* const this;
        this->m_A = 0;
        this->m_B = 0;
    }
    void showInfo() const{
        this->m_A = 1000;

        cout << "m_A = " << m_A << endl;
        cout << "m_B = " << m_B << endl;
    }
    void show() const{

    }

    mutable int m_A; //就算是常函数, 我还是要执意修改
    int m_B;
};

void test01(){

    Person p1;
    p1.showInfo();
    

    //常对象 不可以修改属性
    const Person p2;
    cout << p2.m_A << endl;
    cout << p2.m_B << endl;
    // p2.m_B = 200;
    p2.show(); //p2不可以被修改, 但是show函数可以修改

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
