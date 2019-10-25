/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-25 09:56:40
 */
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

class Base
{
public:
};

//template<class T> T negate<T>//取反仿函数
// template<class T> T plus<T>//加法仿函数
void test01()
{
    negate<int> n;
    cout << n(10) << endl;

    plus<int> p;
    cout << p(1, 1) << endl;
}

//关系类函数对象, 二元
void test02()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(43);
    v.push_back(23);

//template<class T> bool greater<T>//大于
    sort(v.begin(), v.end(), greater<int>());// sort的函数原型肯定是<iterator, iterator, 类名> 那么传进去的最后一个参数也要是对象, 因此用函数对象

    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
}

int main(int argc, char *argv[])
{
    // test01();
    test02();

    return 0;
}
