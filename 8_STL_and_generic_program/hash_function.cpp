/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-26 13:59:41
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <functional>
#include <unordered_set>

using namespace std;

namespace sanjay
{

//产生hash code函数
template <typename T>
inline void hash_combine(size_t &seed, const T &val)
{
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

//函数重载
template <typename T>
inline void hash_val(size_t &seed, const T &val)
{
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(size_t &seed, const T &val, const Types &... args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types &... args)
{
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer
{
public:
    Customer(string f, string l, long l_num)
    :fname(f), lname(l), no(l_num){}

    bool operator==(const Customer& c){
        if(fname == c.fname && lname == c.lname && no == c.no){
            return true;
        }
        return false;
    }

    string fname;
    string lname;
    long no;
};

//自定义的产生哈希code的仿函数
class CustomerHash
{
public:
    size_t operator()(const Customer &c) const
    {
        return hash_val(c.fname, c.lname, c.no);
    }
};

} // namespace sanjay

void test01()
{
    using sanjay::Customer;
    using sanjay::CustomerHash;
    unordered_set<Customer, CustomerHash> set3;
    set3.insert(Customer("Ace", "Hou", 1L));
    set3.insert(Customer("Sabri", "Hou", 2L));
    set3.insert(Customer("Stacy", "Chen", 3L));
    set3.insert(Customer("Mike", "Tseng", 4L));
    set3.insert(Customer("Paili", "Chen", 5L));
    set3.insert(Customer("Light", "Shiau", 6L));
    set3.insert(Customer("Shlly", "Huang", 7L));
    cout << "set3 current bucket_count: " << set3.bucket_count() << endl;

    for(size_t i = 0; i < set3.bucket_count(); ++i){
        cout << "bucket # " << i << " has " << set3.bucket_size(i) << " elements.\n";
    }
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
