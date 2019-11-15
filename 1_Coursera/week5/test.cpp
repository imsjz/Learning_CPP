/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-12 17:12:52
 */
#include <iostream>
using namespace std;

class Test{
    public:
        int n;
        Test(int n_):n(n_){ cout << "构造函数" << endl;}
};

int main(){
    Test t(3);
    t = 5;
    return 0;
}