/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-13 19:49:00
 */
//file String.cpp
#include "String.hpp"
namespace {
    class StringRep{
    friend class String;
    StringRep(const char* s);
    ~StringRep();
    int count;
    char* rep;
    };
}