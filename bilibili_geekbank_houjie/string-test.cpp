/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-09 13:24:14
 */
#include "my_string.h"

int main(){

    MyString s1;
    MyString s2("hello");

    MyString s3(s1);
    cout << s3 << endl;
    s3 = s2;
    cout << s3 << endl;
}
