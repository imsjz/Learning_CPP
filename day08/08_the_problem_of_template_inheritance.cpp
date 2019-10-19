/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 10:01:08
 */
#include <iostream>

using namespace std;

template<class T>
class Base{
public:
    T a_;
};


//child继承于base 必须告诉base中的T的类型, 否则T无法分配内存
class Child: public Base<int>{

};

//另外一种情况
//子类也是类模板
template<class T1, class T2>
class Child2: public Base<T2>{
public:
    Child2(){
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
    T1 b_;
};


void test01(){
    Child2<string, double> child;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
