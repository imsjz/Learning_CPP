/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-10 13:09:13
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Account{
public:
    static double m_rate; //静态成员属于类, 不属于对象
    static void set_rate(const double& x){ m_rate = x;}
};

double Account::m_rate = 8.0;

void test01(){
    Account::set_rate(5.0);

    Account a;
    a.set_rate(7.0);

    cout << sizeof(Account) << endl; //1个字节
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
