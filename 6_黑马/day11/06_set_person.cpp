/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-24 17:16:41
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        name_ = name;
        age_ = age;
    }
    string name_;
    int age_;
};

class MyCompare{
public:
    bool operator()(const Person &p1, const Person &p2){
        if(p1.age_ > p2.age_){
            return true; //降序
        }
        return false;
    }
};

void test01()
{
    set<Person, MyCompare> s1;

    Person p1("大娃", 100);
    Person p2("二娃", 90);
    Person p3("六娃", 10);
    Person p4("爷爷", 1000);


    //插入自定义数据类型, 必须一开始就指定排序规则
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    //显示
    for(set<Person, MyCompare>::const_iterator cit = s1.cbegin(); cit != s1.cend(); ++cit){
        cout << "姓名: " << cit->name_ << " 年龄: " << cit->age_ << endl;
    }
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
