/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 08:48:42
 */
#include <iostream>

using namespace std;

const double pi = 3.14;

class Circle{
public:
    double calculateZC(){
        return 2 * pi * m_R;
    }
    int m_R;
};

void test01(){

    Circle c1;
    c1.m_R = 20;
    cout << "c1 的周长 = " << c1.calculateZC() << endl;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
