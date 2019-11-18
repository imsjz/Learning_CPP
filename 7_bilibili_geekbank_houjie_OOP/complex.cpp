/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-09 12:55:52
 */
#include "complex.h"


Complex&
doapl(Complex* ths, const Complex &r){
    ths->re += r.real();
    ths->im += r.imag();
    return *ths;
}

double
imag(const Complex &x){
    return x.imag();
}

double
real(const Complex &x){
    return x.real();
}

Complex
operator+(const Complex& x, const Complex& y){
    return Complex(real(x) + real(y),
                    imag(x) + imag(y));
}

Complex
operator+(const Complex& x, double y){
    return Complex(real(x) + y,
                    imag(x));
}

Complex
operator+(double x, const Complex& y){
    return Complex(x + real(y),
                    imag(y));
}



//共轭复数
Complex
conj(const Complex &x){
    return Complex(real(x), -imag(x));
}

ostream&
operator<<(ostream &os, const Complex &x){
    return os << "(" << real(x) << ","
            << imag(x) << ")";
}