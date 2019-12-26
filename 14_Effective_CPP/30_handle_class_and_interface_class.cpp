/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-25 10:19:50
 */
#include <iostream>

#include <string>

using namespace std;

//############################################//
//################   如何将文件间的编译依存关系将至最低   ####################//
//############################################//
//两种方法：1. 使用handle class
//        2. 使用interface class

//############################################//
//################   首先考虑这种情况: 下面的实现需要date和address的定义,需要连串编译的依赖关系   ####################//
//############################################//

//需要包含Date和Address的头文件
#include "Date.h"
#include "Address.h"
namespace origin
{
class Person
{
public:
    Person(const string &name, const Date &birthday, const Address &addr);
    string name() const;
    string birthDate() const;
    string address() const;

private:
    string theName;
    Date theBirthDate;
    Address theAddress; //定义式必须要address有定义,而非声明
};

} // namespace origin

//############################################//
//################   解决上面的窘境,1. 用pimpl:pointer to implementation,也称为handle class   ####################//
//############################################//
//############################################//
//################   handle class也即定义两个类,一个类用于声明,另一个类则实现   ####################//
//############################################//
//具体见person_1.h和person_1.cpp的实现
//这样子就实现了声明和实现的分离.
#include "person_1.h"
namespace handle_class
{
void test()
{
    Person p("s", Date(), Address());
    cout << p.address() << endl;
    cout << p.name() << endl;
    cout << p.birthDate() << endl;
}

} // namespace handle_class

//############################################//
//################   第2种: 用interface class, 也即用纯函数来实现.这里不实现了..   ####################//
//############################################//

int main(int argc, char *argv[])
{
    handle_class::test();

    return 0;
}
