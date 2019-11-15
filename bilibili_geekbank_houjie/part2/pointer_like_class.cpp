/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 10:43:05
 */
#include <iostream>

namespace sanjay{

    template<class T>
    class share_ptr
    {
    public:
        T& operator*() const{
            return *px;
        }

        T* operator->() const{
            return px;
        }

        share_ptr(T* p):px(p) {}

    private:
        T* px;
        long* pn;
    };

    struct Foo{
        void method(void){ std::cout << "Foo::method" << std::endl;}
    };

}

using namespace sanjay;

int main(){

    share_ptr<Foo> sp(new Foo);

    Foo f(*sp);

    sp->method();


    return 0;
}