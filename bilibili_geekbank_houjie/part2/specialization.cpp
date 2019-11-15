/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 11:40:53
 */
#include <iostream>
using namespace std;

//------------------------------------
namespace sanjay
{

template <class Key>
struct hash
{
};

template <>
struct hash<char>
{
    size_t operator()(char x) const
    {
        cout << "char " << endl;
        return x;
    }
};

template <>
struct hash<int>
{
    size_t operator()(int x) const
    {
        cout << "int" << endl;
        return x;
    }
};

template <>
struct hash<long>
{
    size_t operator()(long x) const
    {
        cout << "long" << endl;
        return x;
    }
};

} // namespace sanjay

int main()
{
    sanjay::hash<long>()(1000);

    return 0;
}