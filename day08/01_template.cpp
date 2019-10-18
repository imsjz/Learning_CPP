/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 12:55:43
 */
#include <iostream>

using namespace std;

void SwapInt(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

//交换double数据
void SwapDouble(double &a, double &b){
    double tmp = a;
    a = b;
    b = tmp;
}

//类型, 逻辑非常相似
//类型参数化, 泛型编程---模板技术
template<class T> //告诉编译器, 下面如果出现T不要报错, T是一个通用的类型
void MySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

//template<typename T> 等价于 template<class T>
template<typename T>
void MySwap2(){}


void test01(){
    int a = 10;
    int b = 20;
    char c1 = 'c';
    // SwapInt(a, b);
    //1. 自动类型推导, 必须有参数类型才可以推导
    MySwap(a, b);
    //MySwap(a, c1); //推导不出来,所以出错
    cout << a << " " << b << endl;

    //2. 显式指定类型
    MySwap<int>(a, b);

    double a_double = 10.5;
    double b_double = 230.5;
    cout << "before: " << a_double << " " << b_double << endl;
    // SwapDouble(a_double, b_double);

    MySwap(a_double, b_double);


    cout << "after: " << a_double << " " << b_double << endl;

    //模板必须要指定出T才可以使用(如果有类型推导就不需要显式指定)
    MySwap2<double>();
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
