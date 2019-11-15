/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 14:56:51
 */
#include <iostream>
using namespace std;
class A{
    public:
        operator int(){ return 1;} //int()这种形式的运算符重载不需要返回值，返回值就是int
        operator char*() {return nullptr;}
};
int main(){
    A a;
    int n;
    char *p = "New Dragon Inn";
    n = static_cast<int>(3.14);
    cout << n << endl; // 3;
    n = static_cast<int>(a);
    cout << n << endl; //1
    p = static_cast<char*>(a); //nullptr
    cout << p << endl;
    

    // n = static_cast<int>(p); //不能将指针转为整型
    // p = static_cast<char*>(n); //不能将整型转为指针

    return 0;
}