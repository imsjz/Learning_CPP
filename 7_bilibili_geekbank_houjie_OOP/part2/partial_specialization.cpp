/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 11:52:10
 */
#include <iostream>
#include <string>
using namespace std;

namespace sanjay
{

template <class T>
class C
{
public:
    C()
    {
        cout << "T" << endl;
    }
};

template <class T>
class C<T *>
{
public:
    C()
    {
        cout << "T* " << endl;
    }
};

} // namespace sanjay

int main()
{
    sanjay::C<string> obj1;
    sanjay::C<string *> obj2;
}