/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-16 09:59:44
 */
#include <iostream>

using namespace std;

class Animal{
public:
    virtual void Speak(){
        cout << "Animale speak" << endl;
    }
};

class Cat : public Animal{
public:
    void Speak(){
        cout << "Cat speak" << endl;
    }
};

//调用DoSpeak, DoSpeak函数的地址早就绑定好了,(早绑定), 也叫静态联编, 编译阶段就已经确定好了地址
//如果想调用猫的speak,不能提前绑定好函数的地址, 所以需要在运行的时候再去确定函数的地址
//动态联编, 写法Speak方法改为虚函数, 在父类中声明虚函数,发生了多态
//父类的引用或者指针   指向   子类对象  

void DoSpeak(Animal &animal){
    animal.Speak();
}

void test01(){

    Cat cat;
    DoSpeak(cat);

}

void test02(){
    cout << sizeof(Animal) << endl; //增加了virtual关键字之后,字节从1变为8,也就是增加了虚函数表指针
}

void test03(){
    Animal *animal = new Cat; //父类指针指向子类对象
    animal->Speak();
}

int main(int argc, char *argv[]){
    // test01();
    // test02();
    test03();

    return 0;
}
