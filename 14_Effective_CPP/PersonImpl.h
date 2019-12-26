/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-25 10:41:30
 */

#include "Date.h"
#include "Address.h"
#include <string>

class PersonImpl
{
public:
    PersonImpl(const std::string &name, const Date &birthday, const Address &addr);
    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:
    std::string theName;
    Date theBirthDate;
    Address theAddress; //定义式必须要address有定义,而非声明
};


PersonImpl::PersonImpl(const std::string &name, const Date &birthday, const Address &addr):theName(name), theBirthDate(birthday), theAddress(addr){
}

std::string PersonImpl::name() const{
    return theName;
}

std::string PersonImpl::birthDate() const{
    return theBirthDate.toString();
}

std::string PersonImpl::address() const{
    return theAddress.toString();
}