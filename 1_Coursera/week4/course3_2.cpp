/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-10 20:04:06
 */
#include <iostream>
using namespace std;

class Complex{
    double real, imag;
public:
    Complex(double r=0, double i=0):real(r),imag(i){}
    friend ostream& operator<<(ostream &o, const Complex &c);
    friend istream& operator>>(istream &i, Complex &c);
};

ostream& operator<<(ostream &o, const Complex &c){
    cout << c.real << "+" << c.imag << "i";
    return o;
}
istream& operator>>(istream &is, Complex &c){
    string s;
    is >> s;
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos+1, s.length() - pos -2);
    c.imag = atof(sTmp.c_str());
    return is;
}

int main(){
    Complex c;
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    return 0;
}