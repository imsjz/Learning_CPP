/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-09 13:24:07
 */
#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#include <cstring>

using namespace std;

class MyString{
public:
    MyString(const char *cstr=0);
    MyString(const MyString &);
    MyString& operator = (const MyString &);
    ~MyString();
    char *get_c_str() const { return m_data_;}

private:
    char *m_data_;
};

inline
MyString::MyString(const char *cstr){
    if(cstr){
        m_data_ = new char[strlen(cstr) + 1];
        strcpy(m_data_, cstr);
    }
    else{
        m_data_ = new char[1];
        *m_data_ = '\0';
    }
}

inline
MyString::~MyString(){
    delete[] m_data_;
}

inline
MyString::MyString(const MyString& str){
    m_data_ = new char[strlen(str.m_data_) + 1];
    strcpy(m_data_, str.m_data_);
}

inline
MyString& MyString::operator=(const MyString& str){

    if(this == &str){ //检测自我赋值
        return *this;
    }

    delete[] m_data_;
    m_data_ = new char[strlen(str.m_data_) + 1];
    strcpy(m_data_, str.m_data_);
    return *this;
}

inline
ostream& operator<<(ostream& os, const MyString& str){
    os << str.get_c_str();
    return os;
}


#endif