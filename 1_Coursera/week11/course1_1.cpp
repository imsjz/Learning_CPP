/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 16:41:28
 */
#include <memory>
#include <iostream>
using namespace std;
struct A{
    int n;
    A(int v = 0):n(v) {}
    ~A(){
        cout << n << " destructor" << endl;
    }
};
int main(){
    shared_ptr<A> sp1(new A(2));
    shared_ptr<A> sp2(sp1);
    cout << "1)" << sp1->n << "," << sp2->n << endl; //2,2
    shared_ptr<A> sp3;
    A *p = sp1.get(); //获取sp1的指针
    cout << "2)" << p->n << endl;
    sp3 = sp1; //sp3也托管A(2)
    cout << "3)" << (*sp3).n << endl;
    sp1.reset(); //sp1放弃托管A(2)
    if(!sp1)
        cout << "4)sp1 is null" << endl;
    A *q = new A(3);
    sp1.reset(q); //sp1托管q
    cout << "5)" << sp1->n << endl; //3
    shared_ptr<A> sp4(sp1); //sp4托管q
    shared_ptr<A> sp5;
    
    sp1.reset(); //sp1取消托管
    cout << "before end main" << endl;
    sp4.reset(); //sp4取消托管，此时托管计数为0，delete掉q
    cout << "end main" << endl;
    
    return 0;
}