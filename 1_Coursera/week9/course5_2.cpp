/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 14:39:17
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main(){
    string str = "231";
    char szStr[] = "324";
    while(next_permutation(str.begin(), str.end())){
        cout << str << endl;
    }
    cout << "****************" << endl;
    while(next_permutation(szStr, szStr+3)){
        cout << szStr << endl;
    }
    sort(str.begin(), str.end());
    cout << "*****************" << endl;
    while(next_permutation(str.begin(), str.end())){
        cout << str << endl;
    }

    int a[] = {8, 7, 10};
    list<int> ls(a, a + 3);
    while(next_permutation(ls.begin(), ls.end())){
        list<int>::iterator i;
        for(i = ls.begin(); i != ls.end(); ++i){
            cout << *i << " ";
        }
        cout << endl;
    }
    return 0;
}