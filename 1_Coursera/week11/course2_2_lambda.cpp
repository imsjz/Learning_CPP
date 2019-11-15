/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 20:44:12
 */
#include <iostream>
using namespace std;

int main(){
    int x = 100, y = 200, z = 300;
    cout << [](double a, double b){ return a + b;}(1.2, 2.5) << endl; //3.7
    auto ff = [=, &y, &z](int n){
        cout << x << endl;
        y++; z++;
        return n*n;
    };
    cout << ff(15) << endl; //100 255
    cout << y << "," << z << endl; //201,301

    return 0;
}