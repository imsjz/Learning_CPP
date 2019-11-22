/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-22 11:49:07
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void FuncB(int a, int b)
{
    cout << a << endl;
    cout << b << endl;
}
void FuncA()
{
    int i = 0;
    FuncB(++i, i++); //2, 0
}

int main(int argc, char *argv[])
{
    FuncA();

    return 0;
}
