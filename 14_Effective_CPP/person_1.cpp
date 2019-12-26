/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-25 10:56:48
 */
#include "person_1.h"
#include "PersonImpl.h"

Person::Person(const string &name, const Date &birthday, const Address &addr):
pImpl(new PersonImpl(name, birthday, addr)){}

string Person::name() const{
    return pImpl->name();
}

string Person::address() const{
    return pImpl->address();
}

string Person::birthDate() const{
    return pImpl->birthDate();
}