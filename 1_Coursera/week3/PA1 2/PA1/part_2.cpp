/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-10 14:50:44
 */
#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// 在此处补充你的代码
    Sample(const Sample &s){
        v = 10;
    }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}