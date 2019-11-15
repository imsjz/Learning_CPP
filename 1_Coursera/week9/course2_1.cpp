/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-21 11:05:12
 */
#include <iostream>
#include <map>
using namespace std;

int main(){
    typedef multimap<int, double, less<int>> mmid;
    mmid pairs;
    cout << "1)" << pairs.count(15) << endl;
    pairs.insert(mmid::value_type(15, 2.7));
    pairs.insert(mmid::value_type(15, 99.3));
    cout << "2)" << pairs.count(15) << endl;
    pairs.insert(mmid::value_type(30, 111.11));
    pairs.insert(mmid::value_type(10, 22.22));
    pairs.insert(mmid::value_type(25, 33.333));
    pairs.insert(mmid::value_type(20, 9.3));
    for(mmid::const_iterator i = pairs.cbegin();
        i != pairs.cend(); ++i)
        cout << "(" << i->first << "," << i->second << ")" << ",";

    return 0;
}