/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-29 14:22:37
 */
#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(){
    shared_ptr<int> p3 = make_shared<int>(43);
    shared_ptr<string> p4 = make_shared<string>(10, '9');

    //可以用auto来自动获取变量类型
    auto p5 = make_shared<string>();

    return 0;
}
