/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 20:34:34
 */
#include <iostream>

using namespace std;

class MyClass{
public:
    // MyClass(){

    // }

//定义了拷贝构造函数之后，cpp不会再提供任何默认构造函数了 
    MyClass(const MyClass &cls){

    }
    int m_Age;
};

void test01(){

    MyClass mc;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
