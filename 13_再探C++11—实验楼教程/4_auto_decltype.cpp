/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-27 22:02:21
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
//############################################//
//################   1. auto 可用于数组类型的推导   ####################//
//############################################//
void test01(){
    auto i = 5;
    int arr[10] = {0};
    auto auto_arr = arr; //auto可用于数组类型的推导
}

//############################################//
//################   2. decltype   ####################//
//############################################//
//auto只能对变量类型进行推导，如果想要定义一个变量则不行
//
void test02(){
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    cout << typeid(z).name() << endl;
}

//############################################//
//################   3. auto 和 decltype配合   ####################//
//############################################//
//############################################//
//################   c++11的写法   ####################//
//############################################//
template <typename T, typename U>
auto add1(T x, U y) -> decltype(x+y){
    return x + y;
}

//############################################//
//################   下面写法在c++14以后   ####################//
//############################################//
#if 1

template <typename T, typename U>
auto add(T x, U y){
    return x + y;
}

#endif


int main(int argc, char *argv[]){
    test01();
    test02();
    auto result = add1(1,2);
    cout << result << endl;

    return 0;
}
