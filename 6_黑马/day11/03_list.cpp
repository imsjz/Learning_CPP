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
    Person(string name, int age, int height){
        name_ = name;
        age_ = age;
        height_ = height;
    }
    //重载== 让remove可以删除自定义数据类型
    bool operator==(const Person &p){
        if(this->name_ == p.name_ && this->age_ == p.age_ && this->height_ == p.height_){
            return true;
        }
        return false;
    }
    string name_;
    int age_;
    int height_;
};

//年龄相同, 按身高升序排序
bool MyComparePerson(const Person &p1, const Person &p2){
    if(p1.age_ > p2.age_){ //降序排序
        return true;
    }
    else if(p1.age_ == p2.age_){
        return p1.height_ > p2.height_;
    }
    return false;
}

void test03(){
    list<Person> l;
    
    Person p1("亚瑟", 10, 188);
    Person p2("德玛西亚", 20, 23);
    Person p3("火枪", 17, 87);
    Person p4("小龙", 10, 23234);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);

    //按照年龄排序
    l.sort(MyComparePerson);

    //遍历
    for(list<Person>::const_iterator c_it = l.cbegin(); c_it != l.cend(); ++c_it){
        cout << "姓名: " << c_it->name_ << " 年龄: " << c_it->age_ << " 身高: " << c_it->height_ << endl;
    }
    cout << endl;

    l.remove(p3);
    for(list<Person>::const_iterator c_it = l.cbegin(); c_it != l.cend(); ++c_it){
        cout << "姓名: " << c_it->name_ << " 年龄: " << c_it->age_ << " 身高: " << c_it->height_ << endl;
    }
}


int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();

    return 0;
}
