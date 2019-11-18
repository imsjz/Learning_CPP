/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 21:24:11
 */
#include <iostream>

using namespace std;

class Person{

public:
    int m_A; //非静态成员变量,属于对象身上

    void func() {
        cout << "类内声明实现" << endl;
    } //非静态成员函数, 不属于对象身上
    static int m_B; //静态成员变量,不属于对象身上
    static void func2(){}; //静态成员函数,不属于对象
    double m_C;
    void func3();

};

void Person::func3(){
    cout << "func3 类内声明, 类外实现" << endl;
}

void test01(){

    Person P1;
    cout << "size of person " << sizeof(P1) << endl;
    //空类的大小为1 每个实例的对象 都有独一无二的地址, char* 维护这个地址

    //加了m_A , 大小为4字节

    //加了m_C, 大小为16,要内存对齐

    //加了short(在m_A后面加),2个字节,依然是16个字节,说明是8字节对齐,因为是64位系统(64/8=8)

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
