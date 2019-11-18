/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-08 10:11:16
 */
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>
using namespace std;


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



    double re, im;
    friend Complex& doapl(Complex* ths, const Complex &r);

};



double imag(const Complex &x);

double real(const Complex &x);

Complex operator+(const Complex& x, const Complex& y);

Complex operator+(const Complex& x, double y);

Complex operator+(double x, const Complex& y);


//共轭复数
Complex conj(const Complex &x);

ostream& operator<<(ostream &os, const Complex &x);



#endif