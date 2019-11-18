/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-14 14:59:05
 */
#include <iostream>

using namespace std;

class Fraction{
public:
    Fraction(int num, int den = 1)
    : m_numerator(num), m_denominator(den){}
    //把Fraction转为double
    operator double() const {
        return (double)m_numerator / m_denominator;
    }
private:
    int m_numerator; //分子
    int m_denominator; //分母
};
void test01(){
    Fraction f(6, 5);
    double d = 4 + f;
    cout << d << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
