/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 15:31:55
 */
#include <iostream>
#include <bitset>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

bool Greater10(int n){
    return n > 10;
}

int main(){
    const int SIZE = 10;
    int a1[] = {2,8,1,50,3,100,8,9,10,2};
    vector<int> v(a1, a1+SIZE);
    ostream_iterator<int> output(cout, " ");
    vector<int>::iterator location;
    location = find(v.begin(), v.end(), 10);
    if(location != v.end()){
        cout << endl << "1)" << location - v.begin();
    }
    location = find_if(v.begin(), v.end(), Greater10);
    if(location != v.end())
        cout << endl << "2)" << location - v.begin() << endl;

    sort(v.begin(), v.end());//先排序再这折半查找
    for(auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    if(binary_search(v.begin(), v.end(), 9)){
        cout << endl << "3)" << "9 found" << endl;
    }

    return 0;
}