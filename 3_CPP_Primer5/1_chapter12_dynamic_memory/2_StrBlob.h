/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-29 16:12:23
 */
#ifndef STRBLOB_H
#define STRBLOB_H
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <initializer_list>

//定义一个StrBlob类，管理String，对象之间的赋值不是副本，内容指向同一块内存
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type; //size_type只是为了让容器的类型使用与机器无关
    StrBlob();
    StrBlob(std::initializer_list<std::string> il); //initializer_list用来初始化，表示实参个数不知，但类型一致
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加和删除元素
    void push_back(const std::string &t) { data->push_back(t);} //直接简单地push_back即可
    void pop_back();
    //元素访问
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string> > data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string> >(il)){}

void StrBlob::check(size_type i, const std::string &msg) const{
    if(i >= data->size())
        throw std::out_of_range(msg);
}
//元素访问
std::string& StrBlob::front(){
    //如果vector为空，则抛出异常
    check(0, "front on empty StrBlob");
    return data->front();
}
std::string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}
//const版本的元素访问
const std::string& StrBlob::front() const{
    return data->front();
}
const std::string& StrBlob::back() const{
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

#endif