/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-24 16:10:02
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Base
{
public:
};
void test01()
{
    //创建对组
    //第一种
    pair<string, int> p(string("tom"), 100);
    cout << p.first << endl;
    cout << p.second << endl;

    //第二种
    pair<string, int> p2 = make_pair("jerry", 202);
    cout << "姓名: " << p2.first << endl;
    cout << "年龄: " << p2.second << endl;
}

//
void test02()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
    ret = s.insert(10);
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
}

void PrintSet(const set<int> &s)
{
    for (set<int>::const_iterator c_it = s.cbegin(); c_it != s.cend(); ++c_it)
    {
        cout << *c_it << " ";
    }
    cout << endl;
}

//指定set排序规则, 从大到小
//仿函数
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

//set容器排序
void test03()
{
    // set<int> s1;

    set<int, MyCompare> s1; //set里面<>要放类型,不能放函数, 因此,要弄成仿函数

    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);

    // PrintSet(s1);
    for (set<int, MyCompare>::const_iterator c_it = s1.cbegin(); c_it != s1.cend(); ++c_it)
    {
        cout << *c_it << " ";
    }
    cout << endl;

    //从大到小排序
    //在插入之前就指定排序规则
}

int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();

    return 0;
}
