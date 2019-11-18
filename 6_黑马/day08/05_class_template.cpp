/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 20:59:02
 */
#include <iostream>
#include <string>

using namespace std;


//类模板
template<class NameType, class AgeType  = int> //类模板可以有默认类型
class Person{
public:
    Person(NameType name, AgeType age){
        name_ = name;
        age_ = age;
    }
    void ShowAge(){
        cout << "姓名: " << this->name_ << " 年龄: " << this->age_ << endl;
    }

    NameType name_;
    AgeType age_;
};


void test01(){
    //类模板不支持 自动类型推导

    //显示指定类型
    Person<string, int> p("孙悟空", 15);
    p.ShowAge();

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
