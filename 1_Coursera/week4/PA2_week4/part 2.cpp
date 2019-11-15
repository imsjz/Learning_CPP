/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-11 18:01:13
 */
#include <iostream>
using namespace std;
class MyInt  {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
// 在此处补充你的代码
        MyInt& operator-(int n);
};
MyInt& MyInt::operator-(int n){
    nVal -= n;
    return *this;
}
int main ()  {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}