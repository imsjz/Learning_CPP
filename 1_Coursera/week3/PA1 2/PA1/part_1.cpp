/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-10 14:45:09
 */
#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A(int n = 0){ val = n;}
    int& GetObj(){
        return val;
    }
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}