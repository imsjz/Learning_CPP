/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-05 10:36:24
 */
//装饰模式
//需求: 可以给人增加各种服饰的功能, 服饰不定
//用装饰模式, 写一个抽象人类, 用一个装饰器继承这个类, 同时里面聚合抽象人类
#include <iostream>
#include <string>
using namespace std;

//1.抽象人基类
class AbstractPerson{
public:
    AbstractPerson(string name):m_name(name){}
    virtual void show() = 0;
    string m_name;
};

//2.人类
class Person : public AbstractPerson{
public:
    Person(string name) : AbstractPerson(name){
    }
    void show(){
        cout << m_name << " is a Person" << endl;
    }
};

//3.抽象修饰基类
class AbstractDecorator : protected AbstractPerson{
public:
    AbstractPerson* m_ab_person;
    AbstractDecorator(AbstractPerson* ab_person): AbstractPerson(ab_person->m_name){
        m_ab_person = ab_person;
    }
    virtual void show()  = 0;
};

//4. 具体修饰类
class DecoratorA : public AbstractDecorator{
public:
    DecoratorA(AbstractPerson* ab_person) : AbstractDecorator(ab_person){
    }
    virtual void show() override{
        //增加的服饰
        cout << "穿上衣" << endl;
        this->m_ab_person->show(); //原来的服饰
    }
};


int main(int argc, char const *argv[])
{
    AbstractPerson* p1 = new Person("sanjay");
    p1->show();
    //装饰模式, 给p1增加衣服
    AbstractDecorator* cloth = new DecoratorA(p1);
    cloth->show();

    return 0;
}
