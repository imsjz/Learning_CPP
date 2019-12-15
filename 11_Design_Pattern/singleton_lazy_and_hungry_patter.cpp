/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-11 19:03:06
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

//懒汉模式: 懒得吃东西, 也就是等要用的时候再创建实例
class LazySingleton
{
public:
    static LazySingleton *getInstance();
    int a;

private:
    LazySingleton() {}
    LazySingleton(const LazySingleton &) {}
    static LazySingleton *lazy_singleton;
};

LazySingleton *LazySingleton::lazy_singleton = nullptr;
LazySingleton *LazySingleton::getInstance() //要用的时候才创建实例
{
    if (lazy_singleton == nullptr)
    {
        lazy_singleton = new LazySingleton;
        return lazy_singleton;
    }
}

//饿汉模式: 一用实例就创建好了, 创建比较慢, 用比较快
//这个模式比较好, 不会引起线程安全问题
class HungrySingleton
{
public:
    static HungrySingleton *getInstance();
    int a;

private:
    HungrySingleton() {}
    HungrySingleton(const HungrySingleton &) {}
    static HungrySingleton *hungry_singleton;
};

HungrySingleton *HungrySingleton::hungry_singleton = new HungrySingleton;
HungrySingleton *HungrySingleton::getInstance()
{
    return hungry_singleton;
}

void test01()
{
    //测试懒汉模式
    LazySingleton *lazy = LazySingleton::getInstance();
    lazy->a = 10;
    cout << lazy->a << endl;


    //测试饿汉模式
    HungrySingleton* hungry = HungrySingleton::getInstance();
    hungry->a = 20;
    cout << hungry->a << endl;
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
