/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 16:58:59
 */

//file: file_splitter.cpp
#include <iostream>
using namespace std;
class ISplitter
{ //抽象基类
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

class SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() = 0;
    virtual ~SplitterFactory() {}
};

//具体类
class BinarySplitter : public ISplitter
{
public:
    void split()
    {
        cout << "binary" << endl;
    }
};

class TxtSplitter : public ISplitter
{
public:
    void split()
    {
        cout << "text" << endl;
    }
};

//具体工厂
class BinarySplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new BinarySplitter;
    }
};

class TxtSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new TxtSplitter;
    }
};