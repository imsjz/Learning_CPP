/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-15 20:14:08
 * @Descrition:
 * 利用流操纵算子实现： 输入一个实数，先以非科学计数法输出，小数点后面保留5位有效数字；再以科学计数法输出，小数点后面保留7位有效数字。
 */
#include <iostream>
using namespace std;

int main(){
    double a;
    cin >> a;

    //用流对象的成员函数控制输出格式
    cout.setf(ios::fixed);
    cout.precision(5);
    cout << a << endl;
    cout.unsetf(ios::fixed); //清除输出格式

    cout.setf(ios::scientific);
    cout.precision(7);
    cout << a << endl;

    return 0;

}