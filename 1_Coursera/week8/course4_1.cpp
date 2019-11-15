/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-16 13:14:08
 */
#include <iostream>
using namespace std;
//函数对象类
class CMyAverage{
    public:
        CMyAverage(){
            cout << "constructor" << endl;
        }
        double operator()(int a1, int a2, int a3){
            return (double)(a1 + a2 + a3)/ 3;
        }
};

int main(){
    CMyAverage *average = new CMyAverage(); //函数对象
    cout << (*average)(3,2,3);

    return 0;
}