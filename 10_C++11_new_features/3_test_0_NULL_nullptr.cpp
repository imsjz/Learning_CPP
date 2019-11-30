/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-30 14:30:00
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:

};
void fun(int){
    cout << "fun(int)" << endl;
}
void fun(void*){
    cout << "fun(void*)" << endl;
}
void test01(){
    fun(0);
    // fun(NULL); //ambiguous
    fun(nullptr);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
