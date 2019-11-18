/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 13:07:10
 */
#include <iostream>

using namespace std;

// int a;
// int a = 10;

void test(){
    char *p = (char *)malloc(sizeof(64));
}

struct person{
    int myage;
    //void plusAge(); //C语言不可以加函数
};

void test06(){
    int a = 10;
    int b = 20;

    cout << "ret = " << (a > b ? a : b) << endl;
    a > b ? a : b = 100;
    cout << a << endl;
    cout << b << endl;
}

//const增强
const int m_A = 10; //此变量在全局常量区，不可以更改
//const int m_A; //此变量在全局常量区，不可以更改
void test07(){

    const int m_B = 20;

    //1. 可以通过指针修改m_B的值
    int *p = (int *)&m_B;
    *p = 500;
    cout << m_B << endl;
    cout << *p << endl;

    // int *p_a = &m_A;
    // *p_a = 40; //更改会出现段错误
    // printf("m_a = %d\n", m_A);

    int b = 10;
    const int m_c = b;
    int *pc = (int*)&m_c;
    *pc = 300000;
    cout << m_c << endl;
    cout << *pc << endl;

    int size = 3;
    int arr[size]= {1,2,3}; //c不让用变量作为数组的参数

}

struct Person{
    string m_Name;
    int m_Age;
};

void test08(){

    const Person p1 = {"csadaf", 1};
    //p1.m_Age = 20;

    Person *p = (Person *)&p1;
    p->m_Age = 20;
    p->m_Name = "cool";

    cout << p1.m_Age << endl;
    cout << p1.m_Name << endl;

}


int main(int argc, char *argv[]){
    
    //person p;
    //bool flag;
    //test07();
    test08();


    return 0;
}
