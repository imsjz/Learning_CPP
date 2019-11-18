/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 10:03:57
 */
#include <iostream>
#include "game1.h"
#include "game2.h"

using namespace std;
//1. 命名空间必须定义在全局作用域下
namespace A
{
    int a = 10;
    void func();
    class Animal{};
    struct Person{
        char name[64];
        int age;
    };
    namespace B{
        int a = 20;
    }
} // namespace A

//2. 命名空间是开放的,可以随时往里面加东西
namespace A{
    int b = 40;
}

void test(){
    int a = A::B::a;
    cout << a << endl;
    int b = A::b;
    cout << b << endl;
}

//3.当写了无命名空间,相当于写了static xxx, 该变量只能在当前文件使用
namespace{
    int m_c = 0;
    int m_d = 1;
}
//等价于static int m_c = 0; static int m_d = 1;

//4.命名空间可以起别名
namespace verylongname{
    int m_a = 10;
}
void test02(){
    namespace veryshortname = verylongname;
    cout << veryshortname::m_a << endl;
    cout << veryshortname::m_a << endl;
}


int ank = 20; //全局变量
int main(int argc, char *argv[]){
    int ank = 100;
    cout << ank << endl; //打印的是局部
    cout << ::ank << endl;
    cout << A::a << endl;
    LOL::attack();
    kingglory::attack();
    cout << "---------------------" << endl;
    test();
    cout << "=====================" << endl;
    test02();
    return 0;
}
