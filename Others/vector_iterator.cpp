/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-11 20:24:26
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Aiterator
{
    Aiterator(int a) : a_iterator(a) {}
    int a_iterator;
};

class Base
{
public:
    
    Base() : a_base(1){
        sunmengtuo_ = new aa(2);
    }

    int a_base;
    typedef Aiterator aa;
    aa *sunmengtuo_;
};


void test01()
{
    Base base;
    Base::aa ait = *(base.sunmengtuo_);
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
