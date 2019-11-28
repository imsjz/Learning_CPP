/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-28 14:26:44
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
void test_type_trait_output(const T& x){
    cout << "\ntype traits for type: " << typeid(T).name() << endl;

    cout << "is_void\t" << is_void<T>::value << endl;
    cout << "is_integral\t" << is_integral<T>::value << endl;
    cout << "is_floating_point\t" << is_floating_point<T>::value << endl;
    cout << "is_object\t" << is_object<T>::value << endl;
}

int main(int argc, char *argv[]){
    string s;
    test_type_trait_output(s);

    return 0;
}
