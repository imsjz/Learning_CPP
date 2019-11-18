/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-15 09:27:42
 */
#include <iostream>

using namespace std;

class Base1{
public:
    Base1(){
        
        a_ = 10;
    }
    int a_;
};

class Base2{
public:
    Base2(){
        
        a_ = 20;
    }
    int a_;
};

class Son : public Base1, public Base2{
public:
    Son(){
        c_ = 30;
    }
    int c_;
    int d_;
};

//多继承容易产生二义性
void test01(){
    Son son;
    cout << sizeof(son) << endl; //16 bytes

    cout << son.Base1::a_ << endl;
    cout << son.Base2::a_ << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
