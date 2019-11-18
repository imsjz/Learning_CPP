/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-16 16:09:38
 */
#include <iostream>
#include <cstring>

using namespace std;

class Animal{
public:
    virtual void Speak(){
        cout << "动物在说话" << endl;
    }
    // //普通析构 是不会调用子类的析构的, 所以可能会导致释放不干净
    // //利用虚析构来解决这个问题
    // // ~Animal(){
    // virtual ~Animal(){
    //     cout << "动物的析构" << endl;
    // }

    //纯虚析构
    //纯虚析构, 需要声明, 还需要实现: 类内声明, 类外实现
    virtual ~Animal() = 0;
    //如果函数中出现了纯虚析构函数, 那么这个类也是抽象类
    //抽象类,不可实例化对象
};



Animal::~Animal(){
    //纯虚析构实现
    cout << "动物的纯虚析构调用" << endl;
}

//有继承关系的,都会先实例化Animal对象,再实例化Cat对象
class Cat : public Animal{
public:
    Cat(const char *name){
        this->name_ = new char[strlen(name) + 1];
        strcpy(this->name_, name);
    }
    virtual void Speak(){
        cout << "猫在说话" << endl;
    }
    ~Cat(){
        cout << "猫的析构函数" << endl;
        if(name_ != NULL){
            delete [] name_;
        }
    }
    
    char *name_;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->Speak();

    delete animal;
}

// //如果函数中出现了纯虚析构函数, 那么这个类也是抽象类, 不能实例化对象
// void func(){
//     Animal an;
//     Animal *animal = new Animal;
// }


int main(int argc, char *argv[]){
    test01();

    return 0;
}
