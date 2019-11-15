/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 18:26:27
 */
#include <iostream>
#include <stdexcept>
using namespace std;
class Base{
    virtual void func(){}
};
class Derived: public Base{
    public:
        void Print(){}
};

void PrintObj(Base &b){
    try{
        Derived &rd = dynamic_cast<Derived&>(b);
        rd.Print();
    }
    catch(bad_cast &e){
        cerr << e.what() << endl;
    }
}
int main(){
    Base b;
    PrintObj(b);
    return 0;
}