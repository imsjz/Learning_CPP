/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 10:51:05
 */
#include <iostream>

using namespace std;

class Person{
public:
    Person(int age):age_(age){}

    void show_age(){
        cout << "年龄为 " << age_ << endl;
    }

    ~Person(){
        cout << "Person 的析构函数调用" << endl;
    }

    int age_;
};

//智能指针
//用来托管自定义类型的对象，让对象进行自动的释放
class SmartPointer{
public:
    SmartPointer(Person *person){
        this->person_ = person;
    }
    ~SmartPointer(){
        cout << "智能指针析构了" << endl;
        if(this->person_ != NULL){
            delete this->person_;
            this->person_ = NULL;
        }
    }
    Person* operator->(){
        return this->person_;
    }

    //重载
    Person& operator*()    // a + b   == > a operator+(b)  双目　　|| 　*a  a->  单目　编译器应该会自动识别是前面还是后面
    {
        return *this->person_;
    }
private:
    Person *person_;
};

void test01(){

    // Person p1(10); //栈，自动释放
    // Person *p2 = new Person(10);

    // delete p2;

    //智能指针
    SmartPointer smart_pointer(new Person(10));
    smart_pointer->show_age(); //需要重载 --> smart_pointer->->show_age(); 编译器优化了

    (*smart_pointer).show_age();

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
