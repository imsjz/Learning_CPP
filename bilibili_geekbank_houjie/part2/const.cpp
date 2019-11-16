/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-16 13:53:02
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[]){
    string str = "hello";

    str[0] = '0';
    //只能调用string中的非const[]重载
    cout << str << endl;

    const string const_str = "hello";

    cout << const_str[0] << endl;
    ////只能调用string中的const[]重载
    cout << const_str << endl;
    // const_str[0] = '0'; //error

    return 0;
}
