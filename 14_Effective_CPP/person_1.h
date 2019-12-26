/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-25 10:55:39
 */
#include <string>
#include <memory>
#include "Date.h"
#include "Address.h"

using namespace std;
class PersonImpl;
class Date;
class Address;
class Person
{
public:
    Person(const string &name, const Date &birthday, const Address &addr);
    string name() const;
    string birthDate() const;
    string address() const;

private:
    shared_ptr<PersonImpl> pImpl;
};