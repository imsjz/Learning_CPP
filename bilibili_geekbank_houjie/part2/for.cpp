/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 20:40:00
 */
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main(){

    for(int i : { 2,3,3,4,5,6}){
        cout << i << endl;
    }

    vector<int> v = {1,2,3};
    cout << typeid(v).name() << endl;
    return 0;
}