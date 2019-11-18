/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 17:14:39
 */
#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(string name, int age):name_(name), age_(age){}
    string name_;
    int age_;
};

template<class T>
bool Compare(T &a, T &b){
    if(a == b){
        return true;
    }
    return false;
}


//通过第三代具体化自定义数据类型, 解决上诉问题
//如果具体化能够优先匹配, 那么就选择具体化
//语法 template<> 返回值 函数名<具体类型>(参数)
template<> bool Compare<Person>(Person &a, Person &b){
    if(a.name_ == b.name_ && a.age_ == b.age_){
        return true;
    }
    return false;
}

void test01(){
    int a = 10;
    int b = 20;
    bool ret = Compare(a , b);
    cout << ret << endl;
    int c = 20;
    cout << Compare(b, c) << endl;

    Person p1("张三", 20);
    Person p2("李四", 43);

    cout << Compare(p1,p2) << endl;


}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
