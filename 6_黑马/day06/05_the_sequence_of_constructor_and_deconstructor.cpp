/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 20:08:34
 */
#include <iostream>

using namespace std;
class Base{
public:
    Base(){
        cout << "基类的构造函数" << endl;
    }
    ~Base(){
        cout << "基类的析构函数" << endl;
    }
};

//公有继承
//子类中 会继承父类的私有成员，只是被编译给隐藏了起来，访问不到私有成员

////////////子类会继承父类的成员属性,成员函数////////////////
//但是子类不会继承  父类  的   构造函数和析构函数
//只有父类自己知道如何构造和析构自己的属性,而子类不知道
class SonPublic: public Base{
public:
    SonPublic(){
        cout << "子类构造函数" << endl;
    }
    ~SonPublic(){
        cout << "子类析构函数" << endl;
    }
};

class Base2{
public:
    Base2(int a){
        this->a_ = a;
        cout << "Base2 有参构造" << endl;
    }

    int a_;
};

class Son2: public Base2{
public:
    Son2(int b):Base2(b){ //利用初始化列表方式 显式调用  有参构造
        cout << "Son2 构造" << endl;

    }
};

void test01(){

    // Base b1;
    SonPublic son_public;

}

void test02(){

    Son2 son2(10);
}
int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
