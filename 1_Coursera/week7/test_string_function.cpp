/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-14 17:49:23
 */
#include <iostream>
#include <string>
using namespace std;

class test{
    public:
        void fun(){}
};

int main(){
    string s1("hello world");
    int len = s1.length();
    char *p2 = new char[len+1];
    s1.copy(p2, 5, 0);
    p2[5] = 0;
    cout << p2 << endl;
    // test::fun();
    return 0;
}