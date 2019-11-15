/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-14 15:00:23
 */
#include <iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    freopen("test.txt", "w", stdout);
    if(y == 0)
        cerr << "error." << endl;
    else
        cout << x / y;
    return 0;
}