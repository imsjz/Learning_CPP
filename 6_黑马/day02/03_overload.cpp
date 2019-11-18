/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 09:54:33
 */
#include <iostream>

using namespace std;

//函数重载+默认参数
// void func(int a, int b = 10){

// }

// void func(int a){

    
// }

//引用重载
void func1(int &a){

}

void func1(const int &a){
    cout << "const int &a" << endl; //
}

void test01(){
    int a;
    func1(a);
    //func1(10); 
    func1(10);

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
