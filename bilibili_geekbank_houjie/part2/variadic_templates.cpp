/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 19:59:27
 */
#include <iostream>
#include <bitset>

using namespace std;

void print(){

}

template<typename T, typename... Types>
void print(const T& first_arg, const Types&... args){

    cout << first_arg << endl;
    print(args...);
    cout << sizeof...(args) << endl;
}

int main(){

    print(7.5, "hello", bitset<16>(377), 42);

    return 0;
}