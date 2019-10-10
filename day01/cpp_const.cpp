/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 15:53:25
 */
#include <iostream>

using namespace std;

int c = 20;
extern const int b = c;

int main(int argc, char *argv[]){
    
    extern const int a;

    int *p = (int *)&b;
    *p = 56;
    cout << *p << endl; //56
    cout << b << endl; //56 说明不管是不是全局，只要是用变量对const值进行初始化的，cpp都会给此变量分配内存
    cout << a << endl;

    return 0;
}
