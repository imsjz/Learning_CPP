/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-29 15:36:42
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class Base
{
public:
};

/*
	find算法 查找元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 查找的元素
	@return 返回查找元素的位置
*/

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end())
    {
        cout << "找到了数据" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}

class Person
{
public:
    Person(string name, int age) : name_(name), age_(age) {}
    string name_;
    int age_;
    //重载==运算符
    bool operator==(const Person &p)
    {
        if (this->name_ == p.name_ && this->age_ == p.age_)
        {
            return true;
        }
        return false;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("aaa", 23);
    Person p2("bbb", 323);
    Person p3("ccc", 30);
    Person p4("ddd", 32);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator pos = find(v.begin(), v.end(), p2);

    if (pos != v.end())
    {
        cout << "找到了数据" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}

class MyCompare : public binary_function<Person *, Person *, bool>
{
public:
    bool operator()(const Person *p1, const Person *p2) const
    { //用const 是因为继承了了binary_function, 重写了operator()
        if ((p1->age_ == p2->age_) && (p1->name_ == p2->name_))
        {
            return true;
        }
        return false;
    }
};

void test03()
{
    vector<Person *> v;
    Person p1("aaa", 23);
    Person p2("bbb", 323);
    Person p3("ccc", 30);
    Person p4("ddd", 32);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    Person *p = new Person("bbb", 323);
    // vector<Person*>::iterator pos = find(v.begin(), v.end(), p); //用find查找指针是不行的
    //要用find_if
    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare(), p));

    if (pos != v.end())
    {
        cout << "找到了数据" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}

class GreaterThanFour{
public:
    bool operator()(int val){
        return val >= 4;
    }
};


void test04()
{
    /*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  value回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
*/
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(4);
    }
    int num = count(v.begin(), v.end(), 4);
    cout << num << endl;

    v.push_back(5);
    v.push_back(2);

/*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  callback 回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
    count_if(iterator beg, iterator end, _callback);
*/
    int num_if = count_if(v.begin(), v.end(), GreaterThanFour());
    cout << "num_if = " << num_if << endl; //11

}

int main(int argc, char *argv[])
{
    // test01();
    // test02();
    // test03();
    test04();

    return 0;
}
