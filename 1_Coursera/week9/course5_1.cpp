/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 13:26:27
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(){
    int a[5] = {1,2,3,2,5};
    int b[6] = {1,2,3,2,5,6};
    ostream_iterator<int> oit(cout, ",");
    int *p = remove(a, a+5, 2);
    cout << "1)"; copy(a, a+5, oit); cout << endl;
    cout << "2)" << p - a << endl;
    vector<int> v(b, b+6);
    remove(v.begin(), v.end(), 2);
    cout << "3)"; copy(v.begin(), v.end(), oit); cout << endl;
    cout << "4)"; cout << v.size() << endl;

    return 0;
}