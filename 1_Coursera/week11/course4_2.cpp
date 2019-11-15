/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 18:18:19
 */
#include <iostream>
#include <string>
using namespace std;
class CException{
    public:
        string msg;
        CException(string str):msg(str){}
};
double Devide(double x, double y){
    if(y == 0)
        throw CException("devided by zero");
    cout << "in devide" << endl;
    return x / y;
}
int CountTax(int salary){
    try{
        if(salary < 0)
            throw -1;
        cout << "counting tax" << endl;
    }
    catch(int e){
        cout << "salary < 0" << endl;
    }
    cout << "tax counted" << endl;
    return salary * 0.15;
}

int main(){
    double f = 1.2;
    try{
        CountTax(-1);
        f = Devide(1, 0);
        cout << "end of block" << endl;
    }
    catch(CException e){
        cout << e.msg << endl;
    }
    cout << "f=" << f << endl;
    cout << "finished" << endl;
    return 0;
}