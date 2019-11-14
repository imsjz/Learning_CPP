/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-14 14:59:05
 */
#include <iostream>

using namespace std;

class Fraction{
public:
    explicit Fraction(int num, int den = 1)
    : m_numerator(num), m_denominator(den){}
    
    operator double() const {
        return (double)m_numerator / m_denominator;
    }
    Fraction operator+(const Fraction& f){
        return Fraction(m_numerator + f.m_numerator, m_denominator + f.m_denominator);
    }

private:
    int m_numerator; //分子
    int m_denominator; //分母
};
void test01(){
    Fraction f(3, 5);
    double d2 = f + 4; //调用non-explicit ctor 将 4 转为 Fraction(4, 1)
    //然后调用operator+
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
