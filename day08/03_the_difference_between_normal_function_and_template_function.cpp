/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 13:41:02
 */
#include <iostream>

using namespace std;

//1. 普通函数与函数模板的区别
template<class T>
T MyPlus(T a, T b){
    return a + b;
}

int MyPlus2(int a, int b){
    return a + b;
}

void test01(){
    int a = 10;
    int b = 20;
    char c = 'c'; //ascii 99

    cout << MyPlus2(a, c) << endl; //10 + 99 = 109 , 普通的函数可以进行隐式类型转换
    // MyPlus(a, c); //类型推导不出来, 函数模板不可以进行隐式类型转换
}

//2.普通函数和函数模板的调用规则
template<class T>
void MyPrint(T a, T b){
    cout << "模板调用的myprint" << endl;
}


//函数模板
template<class T>
void MyPrint(T a, T b, T c){
    cout << "模板调用的myprint(三个参数)" << endl;
}

// //用函数模板生成的函数称为  模板函数
// void MyPrint(int a, int b , int c){

// }

// void MyPrint(int a, int b);
void MyPrint(int a, int b){
    cout << "普通函数的调用" << endl;
}

void test02(){
    int a = 10;
    int b = 20;

    //1.如果出现重载, 优先使用普通函数调用, 如果没有实现, 出现错误
    // MyPrint(a ,b);

    //2.如果想强制调用模板, 那么可以使用空参数列表
    MyPrint<>(a, b);

    //3. 函数模板可以发生重载
    int c = 30;
    MyPrint(a,b , c);

    //4. 如果函数模板可以产生更好的匹配, 那么优先调用函数模板
    char c1 = 'c';
    char d = 'd';

    MyPrint(c1, d);
}

int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
