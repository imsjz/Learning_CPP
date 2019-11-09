/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-08 10:11:16
 */
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>
using namespace std;

class Complex;

inline Complex&
__doapl(Complex* ths, const Complex &r){
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline double
imag(const Complex &x){
    return x.imag();
}

inline double
real(const Complex &x){
    return x.real();
}

inline Complex
operator+(const Complex& x, const Complex& y){
    return Complex(real(x) + real(y),
                    imag(x) + imag(y));
}

inline Complex
operator+(const Complex& x, double y){
    return Complex(real(x) + y,
                    imag(x));
}

inline Complex
operator+(double x, const Complex& y){
    return Complex(x + real(y),
                    imag(y));
}

inline Complex
operator+(const Complex &x){
    return x;
}

inline Complex
operator-(const Complex &x){
    return Complex(-real(x), -imag(x));
}

//共轭复数
inline Complex
conj(const Complex &x){
    return Complex(real(x), -imag(x));
}

ostream&
operator<<(ostream &os, const Complex &x){
    return os << "(" << real(x) << ","
            << imag(x) << ")";
}


class Complex
{
public:
    Complex(double r = 0, double i = 0)
    : re(r), im(i)
    {}
    Complex& operator += (const Complex&);
    double real() const { return re; }
    double imag() const { return im; }

    int func(const Complex &param){
        return param.re + param.im;
    }


private:
    double re, im;
    friend inline Complex& __doapl(Complex* ths, const Complex &r);

};

inline Complex&
Complex::operator += (const Complex &r){
    return __doapl(this, r);
}


#endif