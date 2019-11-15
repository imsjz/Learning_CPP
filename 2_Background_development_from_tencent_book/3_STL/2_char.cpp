/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-30 13:01:34
 */
#include <iostream>
using namespace std;

int main(){
    char str[12] = "Hello";
    char *p = str;
    *p = 'h';

    const char *ptr = "Hello";
    //*ptr = 'h'; //error
    return 0;
}