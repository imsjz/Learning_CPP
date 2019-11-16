/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 21:22:31
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


int main(int argc, char *argv[]){
    
    int x = 0;

    int* p = &x; //
    int& r = x;  //r 代表x, 现在r, x都是0

    cout << "sizeof(p) = " << sizeof(p) << endl; //8
    cout << "sizeof(x) = " << sizeof(x) << endl; //4
    cout << "sizeof(r) = " << sizeof(r) << endl; //4 , 编译器造成的假象

    cout << "&x = " << &x << endl;
    cout << "&r = " << &r << endl;

    return 0;
}
