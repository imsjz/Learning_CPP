/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 19:59:18
 */
#include <iostream>

using namespace std;

class Base{
public:
    int a_;
protected:
    int b_;
private:
    int c_;
};

//公有继承
//子类中 会继承父类的私有成员，只是被编译给隐藏了起来，访问不到私有成员
class SonPublic: public Base{
public:
    int d_;
};


void test01(){

    cout << sizeof(SonPublic) << endl; //16

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
