#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //number definition
    short s = 10;
    int i = -1000;
    long l = 1000000;
    float f = 230.45;
    double d = 200.34234;

    //math operation
    cout << "sin(d): " << sin(d) << endl;
    cout << "abs(i): " << abs(i) << endl;
    cout << "floor(d): " << floor(d) << endl; // 200
    cout << "sqrt(f): " << sqrt(f) << endl; //-->
    cout << "pow(d, 2): " << pow(d, 2) << endl;

    return 0;
}
