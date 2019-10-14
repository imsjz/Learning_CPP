/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 20:55:54
 */
#include <iostream>

using namespace std;

class Base{
public:
    Base(){
        
        a_ = 100;
    }

    void func(){
        cout << "Base func调用" << endl;
    }
    void func(int a){
        cout << "Base func带参调用" << endl;
    }
    int a_;
};

class Son : public Base{
public:
    Son(){
        a_ = 200;
    }
    void func(){
        cout << "Son func调用" << endl;
    }
    int a_;
};
void test01(){
    Son s1;
    cout << s1.a_ << endl;

    //想调用 父类中的a_
    cout << s1.Base::a_ << endl;

    s1.func();
    //调用父类的func
    s1.Base::func();

    //如果子类和父类有同名的函数,属性, 子类会覆盖父类的成员吗? 不会
}

void test02(){
    Son s2;

    //如果子类和父类的成员函数名称相同,子类会把父类的所有同名版本都隐藏掉
    //想要调用父类的方法,必须加作用域
    // s2.func(10);
    s2.Base::func(10);
}
int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
