/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-30 15:28:00
 */
#include <iostream>
#include <cstring>
using namespace std;

class String{
public:
    String();
    String(const char *str);
    String(const String &other);
    ~String(); //析构函数
    String& operator=(const String &rhs);
    String& operator+(const String &rhs);
    bool operator==(const String &rhs);
    int getLength();
private:
    char *m_data;
};
String::String():m_data(new char[1]){m_data[0] = 0;}
String::String(const char *str){
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);
}
String::~String(){
    if(m_data){
        delete [] m_data;
        m_data = nullptr;
    }
}
//复制构造函数
String::String(const String &other){
    //不用考虑本身的内存情况，因为这些构造函数都是一开始调用的
    m_data = new char(strlen(other.m_data) + 1);
    strcpy(m_data, other.m_data);
}

//赋值函数
String& String::operator=(const String &rhs){
    //判断是否为自赋值
    if(this != &rhs){
        delete [] m_data;
        m_data = new char[strlen(rhs.m_data) + 1];
        strcpy(m_data, rhs.m_data);
    }
    return *this;
}
//拼接函数
String& String::operator+(const String &rhs){
    //三种情况，本身为空，rhs为空，两者都不为空
    String newString;
    if(!m_data)
        newString = rhs;
    else if(!rhs.m_data)
        newString = *this;
    else{
        //两者都不为空
        newString.m_data = new char[strlen(m_data) + strlen(rhs.m_data) + 1];
        strcpy(newString.m_data, m_data);
        strcat(newString.m_data, rhs.m_data);
    }
    return newString;
}
bool String::operator==(const String &rhs){
    if(strlen(m_data) != strlen(rhs.m_data))
        return false;
    else
        return strcmp(m_data, rhs.m_data)?false : true;
}
int String::getLength(){
    return strlen(m_data);
}

