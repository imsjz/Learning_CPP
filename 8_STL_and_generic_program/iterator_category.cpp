/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-25 11:24:12
 */
//---------------------------------------------------
#include <iostream> // std::cout
#include <iterator> // std::iterator_traits
#include <typeinfo> // typeid
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

namespace sanjay
{
//以下5个方法都是重载, 虽然有些是继承关系, 但是也视为函数签名不一样, 同时只需要cout, 因此不需要拿到参数, 不需要在形参中声明变量
void display_category(random_access_iterator_tag)
{
    cout << "random_access_iterator" << endl; //随机访问迭代器, 继承自bidirectional_iterator
}
void display_category(bidirectional_iterator_tag)
{
    cout << "bidirectional_iterator" << endl; //双向迭代器, 继承于前向迭代器
}
void display_category(forward_iterator_tag)
{
    cout << "forward_iterator" << endl; // 前向迭代器, 继承于input_iterator
}
void display_category(output_iterator_tag)
{
    cout << "output_iterator" << endl;
}
void display_category(input_iterator_tag)
{
    cout << "input_iterator" << endl;
}

template <typename I>
void display_category(I itr)
{
    typename iterator_traits<I>::iterator_category cagy; //使用typename的原因, 使用typename 说明后面的是类型, 
    display_category(cagy); //调用前面5个函数

    cout << "typeid(itr).name()= " << typeid(itr).name() << endl;
    cout << endl;
}

void test_iterator_category()
{
    cout << "\ntest_iterator_category().......... \n";
    cout << endl;

    display_category(array<int, 10>::iterator());    //random
    display_category(vector<int>::iterator());       //random
    display_category(list<int>::iterator());         //bidirectional
    display_category(forward_list<int>::iterator()); //forward
    display_category(deque<int>::iterator());        //random

    display_category(set<int>::iterator());
    display_category(map<int, int>::iterator());
    display_category(multiset<int>::iterator());
    display_category(multimap<int, int>::iterator());
    display_category(unordered_set<int>::iterator()); //forward
    display_category(unordered_map<int, int>::iterator());
    display_category(unordered_multiset<int>::iterator());
    display_category(unordered_multimap<int, int>::iterator());

    display_category(istream_iterator<int>());
    display_category(ostream_iterator<int>(cout, ""));
}
} // namespace sanjay

int main()
{
    sanjay::test_iterator_category();

    return 0;
}