/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 17:08:25
 */
#include <memory>
#include <iostream>
using namespace std;

int main(){
    int *p1 = NULL;
    int *p2 = nullptr;
    shared_ptr<double> p3 = nullptr;
    if(p1 == p2)
        cout << "equal 1" << endl;
    if(p3 == nullptr)
        cout << "equal 2" << endl;
    //if(p3 == p2); //error,类型不匹配
    if(p3 == NULL)
        cout << "equal 4" << endl;
    // bool b = nullptr;
    // int i = nullptr;
    return 0;
}