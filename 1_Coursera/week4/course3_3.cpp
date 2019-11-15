/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-10 22:00:35
 */
#include <iostream>
using namespace std;

class CDemo{
    int n;
public:
    CDemo(int i=0):n(i){}
    CDemo operator++();//前置
    CDemo operator++(int); //后置
    operator int() {return n;}
    friend CDemo operator--(CDemo &c);
    friend CDemo operator--(CDemo &c, int);
};

CDemo CDemo::operator++(){
    n++;
    return *this;
}

CDemo CDemo::operator++(int k){
    CDemo tmp(*this);
    n++;
    return tmp;
}

CDemo operator--(CDemo &c){
    c.n--;
    return c;
}

CDemo operator--(CDemo &c, int){
    CDemo tmp(c);
    c.n--;
    return tmp;
}

int main(){
    CDemo d(5);
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    cout << (d--) << ",";
    cout << d << ",";
    cout << (--d) << ",";
    cout << d << endl;
    return 0;
}