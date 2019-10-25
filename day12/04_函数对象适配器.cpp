/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-25 11:06:33
 */
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

class MyPrint : public binary_function<int, int, void>
{
public:
    void operator()(int val, int start) const
    {
        cout << "val = " << val << " start = " << start << " val + start = " << val + start << endl;
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    cout << "请输入起始值: " << endl;
    int num;
    cin >> num;

    // for_each(v.begin(), v.end(), bind2nd(MyPrint(),  num));
    for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}
//第一步: 绑定数据 bind2nd
//第二步: 继承 public binary_function<参数类型1, 参数类型2, 返回类型>
//第三步: 加const修饰operator()

class GreaterThanFive : public unary_function<int, bool>
{
public:
    bool operator()(int val) const
    {
        return val > 5;
    }
};

//取反适配器
void test02()
{
    //一元取反
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    //查找大于5的数字
    //需求改为 找小于5的数字
    // vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThanFive()));
    //等价于
    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
    if (pos != v.end())
    {
        cout << "找到小于5的数字为" << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}
//1. 一元取反适配器 not1
//2. 继承 unary_function<参数类型1, 返回值类型>
//3. operator() 函数加上const修饰


void MyPrint03(int val, int start){
    cout << val + start << endl;
}

//函数指针适配器
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    //将函数指针 适配为  函数对象
    //ptr_fun
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03), 100)); //MyPrint03是指针
}


//成员函数适配器 //todo

int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();

    return 0;
}
