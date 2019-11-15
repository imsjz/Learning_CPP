/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 16:16:45
 */
#include <iostream>
using namespace std;
int main(){
    double m, n;
    cin >> m >> n;
    try{
        cout << "before dividing." << endl;
        if (n == 0)
            throw -1; //抛出int类型异常
        else if(m == 0)
            throw -1.0; //抛出double型异常
        else
        {
            cout << m / n << endl;
        }
        cout << "after dividing." << endl;
    }
    catch(double d){
        cout << "catch(double)" << d << endl;
    }
    catch(...){
        cout << "catch(...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}