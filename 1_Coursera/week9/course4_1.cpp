/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-21 17:39:23
 */
#include <iostream>
#include <algorithm>
using namespace std;
class A{
    public:
        int n;
        A(int n_):n(n_){}
};
bool operator<(const A &a1, const A &a2){
    cout << "< called" << endl;
    if(a1.n == 3 && a2.n == 7)
        return true;
    else
    {
        return false;
    }
}
int main(){
    A aa[] = {3, 5, 7, 2, 1};
    cout << min_element(aa, aa+5)->n << endl; //取3为最小，用5 < 3 比较，返回false，说明5比3大；以此类推..
    cout << max_element(aa, aa+5)->n << endl; //取3为最大，用3 < 5比较，返回false，说明3比5大，用3<7比较，返回true说明3比7小，于是
    //取7为最大，用7<2，返回false；用7<1，返回false，于是7的对象最大，返回这个的迭代器(或指针)

    return 0;
}