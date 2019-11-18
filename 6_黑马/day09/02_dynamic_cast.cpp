/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 15:50:56
 */
#include <iostream>

using namespace std;

//动态转换

void test01(){
    //基础类型不可以转换
    char c = 'a';
    //dynamic_cast非常严格, 失去精度, 或者不安全都不可以转换
    // double d = dynamic_cast<double>(c);
}

//父子类转换
class Base{
    virtual void func(){}
};
class Child : public Base {
    void func(){}
};
class Other{};

void test02(){
    Base *base_pointer = NULL;
    Child *child_pointer = NULL;
    //子类转父类, 安全
    Base *base_p = dynamic_cast<Base*>(child_pointer);

    //父类转子类, 不安全
    // Child *child_p = dynamic_cast<Child*>(base_pointer); //这样需要多态, 什么意思???

    //意思就是, 如果发生了多态, 那么可以让基类转为派生类, 向下转换
    Base *poly_base = new Child; //发生了多态
    Child *poly_child = dynamic_cast<Child*>(poly_base);
}

int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
