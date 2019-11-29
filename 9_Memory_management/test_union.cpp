/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-29 16:23:12
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base
{
public:
    int a;
    double b;
};
union two_member {
    int a;
    char b;
    //如果再加一个int
    
};
struct AirplaneRep
{
    unsigned long miles; // 8
    char types;          //9
};

class Airplane
{
private:
    struct AirplaneRep_1
    {
        unsigned long miles; // 8
        char types;          //9
    };

private:
    union{
        AirplaneRep temp; //16
        Airplane* a_p; //8
    };
}; // bytes : 16
class A{
public:
    int a;
    char b;
    double c;
    char d;
};
class B{
public:
    char a;
    double f;
    char c;
};



void test01()
{
    cout << sizeof(two_member) << endl;  //4
    cout << sizeof(AirplaneRep) << endl; //16
    cout << sizeof(long) << endl; //8
    cout << sizeof(Airplane) << endl; //16字节

    cout << " ===============" << endl;
    cout << sizeof(A) << endl; //24
    cout << sizeof(B) << endl; //24
    cout << sizeof(Base) << endl;
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
