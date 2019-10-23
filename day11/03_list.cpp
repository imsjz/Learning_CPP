/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 20:17:16
 */
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Base
{
public:
};
//list是双向循环链表
// void test01()
// {
//     list<int> my_list;
//     for (int i = 0; i < 10; ++i)
//     {
//         my_list.push_back(i);
//     }

//     list<int>::_Nodeptr node = my_list._MyHead->_Next; //头结点下一个

//     for (int i = 0; i < my_list._Mysize * 2; i++)
//     {

//         cout << "Node:" << node->_Myval << endl;

//         node = node->_Next;

//         if (node == my_list._Myhead)
//         {

//             node = node->_Next;
//         }
//     }
// }

void print_list(const list<int> &l){
    for(list<int>::const_iterator cit = l.cbegin(); cit != l.cend(); ++cit){
        cout << *cit << " ";
    }
    cout << endl;
}


void test01(){
    list<int> l(10, 10);
    list<int> l2(l.begin(), l.end());

    print_list(l);
    print_list(l2);

    l2.push_back(100);

    //逆序打印
    for(list<int>::reverse_iterator rit = l2.rbegin(); rit != l2.rend(); ++rit){
        cout << *rit << " ";
    }
    cout << endl;

    //list迭代器不支持随机访问
    list<int>::iterator it_begin = l2.begin();
    // it_begin = it_begin + 1; 

    //插入数据
    list<int> l3;
    l3.push_back(10);
    l3.push_back(20);
    l3.push_back(40);
    l3.push_front(2323);
    l3.push_front(3245234);

    print_list(l3);

    //删除两端的数据
    l3.pop_front(); //头删
    l3.pop_back(); //尾删

    print_list(l3);

    l3.insert(l3.begin(), 100000);
    l3.push_back(10);
    print_list(l3);

    l3.remove(10);
    print_list(l3);

}

bool MyCompare(int v1, int v2){
    return v1 > v2;
}

//reverse(); //反转链表
//sort() //list 排序
void test02(){
    list<int> l;
    l.push_back(10);
    l.push_back(23);
    l.push_back(234);
    l.push_back(324534);

    //l: 10 23 234 324534

    l.reverse();
    print_list(l);

    // sort(l.begin(), l.end()); //所有不支持随机访问的迭代器, 不可以用系统提供的算法
    //如果不支持用系统提供的算法, 那么这个类内部会提供
    l.sort();

    print_list(l);

    //逆序排序
    l.sort(MyCompare);
    print_list(l);

}

//自定义数据类型
class Person{
public:
    Person(string name, int age){
        name_ = name;
        age_ = age;
    }
    string name_;
    int age_;
};



int main(int argc, char *argv[])
{
    // test01();
    test02();

    return 0;
}
