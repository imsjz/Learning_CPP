/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-16 17:34:00
 */
#include <iostream>
#include <list>
using namespace std;

class MyLess{
    public:
        bool operator()(const int &c1, const int &c2){
            return (c1 % 10)  < (c2 % 10);
        }
};
//函数模板
template<class T>
void Print(T first, T last){
    for(; first != last; ++first)
        cout << *first << ",";
}
int main(){
    const int SIZE = 5;
    int a[SIZE] = { 5, 21, 14, 2, 3};
    list<int> lst(a, a+SIZE);
    //根据个位数进行排序
    lst.sort(MyLess());
    Print(lst.begin(), lst.end());
    cout << endl;

    //逆序
    lst.sort(greater<int>());
    Print(lst.begin(), lst.end());
    cout << endl;
    return 0;
}