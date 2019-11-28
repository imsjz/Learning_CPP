/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-28 16:13:26
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <complex>

using namespace std;

class Base{
public:
    Base(int a, int b): a_(a), b_(b){}

    int a_;
    int b_;

};
void test01(){
    void *p1 = malloc(512); //申请512个字节
    free(p1);

    complex<int>* p2 = new complex<int>; //new object
    delete p2;

    void* p3 = ::operator new(512); //全局new函数
    ::operator delete(p3);

#ifdef __GNUC__
    void* p4 = allocator<int>().allocate(7); //分配7个int
    allocator<int>().deallocate((int*)p4, 7); //需要指定地址, 和大小
    cout << "__GNUC__" << endl;

#endif
}

void test02(){
    Base* b;
    void* mem = operator new(sizeof(Base));
    b = static_cast<Base*>(mem);
    //b->Base::Base(1,2); //这种呼叫ctor的方式只有编译器才可以做到
    new(b)Base(1,2); //但是可以用这种方式

    cout << b->a_ << " " << b->b_ << endl;

}

int main(int argc, char *argv[]){
    test02();

    return 0;
}
