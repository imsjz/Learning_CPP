/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 13:53:18
 */
#include <iostream>

using namespace std;



//静态转换
//基础类型
void test01(){
    char c = 'c';

    double d = static_cast<double>(c);

    cout << "d = " << d << endl;
}

//父子之间转换
class Base{};
class Child: public Base{};
class Other{};
void test02(){

    Base *base = NULL;
    Child *child = NULL;

    //把base*转为child*类型, 不安全
    Child *child2 = static_cast<Child*>(base);

    //把child*转为base*, 安全
    Base *base2 = static_cast<Base*>(child);

    //转other类型, 转换无效
    // Other *other = static_cast<Other*>(base);
}

//继承关系引用之间也可以转换
void test03(){
    Base base;
    Child child;
    Base &base_ref = base;
    Child &child_ref = child;

    //子类引用转换成父类引用, 安全
    Base &base_ref_child = static_cast<Base&>(child_ref);

    //父类引用转为子类引用,不安全
    Child &child_ref_base = static_cast<Child&>(base_ref);
}
int main(int argc, char *argv[]){
    // test01();

    // test02();

    test03();

    return 0;
}
