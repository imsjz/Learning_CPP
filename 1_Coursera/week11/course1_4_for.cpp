/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 17:12:12
 */
#include <iostream>
#include <vector>
using namespace std;
struct A{int n; A(int i):n(i){}};
int main(){
    int ary[] = {1,2,3,4,5};
    for(int &it: ary)
        it *= 10;
    for(int e: ary)
        cout << e << " ";
    cout << endl;
    vector<A> v(ary, ary+5);
    for(auto &it: v)
        it.n *= 10;
    for(A e: v)
        cout << e.n << " ";
    cout << endl;

    return 0;
}