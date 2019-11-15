/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-10 16:51:43
 */
#include <iostream>
using namespace std;

class Test{
    public:
        int n;
        Test(int n){
            cout << "构造函数" << endl;
        }
        Test(const Test &test){
            n = test.n + 1;
            cout << "复制构造函数" << endl;
        }
};

int main(){
    Test a(10);
    Test b(20);
    a = b;
    return 0;
}