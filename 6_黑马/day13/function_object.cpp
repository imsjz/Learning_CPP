/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-02 20:37:52
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:
    bool operator()(int a){
        cout << a << endl;
    }
};
void test01(){
    Base base;
    base(3);
    base.operator()(3);
}

// T 需要支持输出流运算符
template <class T>
class Print{
public:
    void operator()(T elem) const{
        cout << elem << " ";
    }
};

void test02(){
    vector<int> v(10);
    int init = 0;
    std::generate(v.begin(), v.end(), [&init]() { return init++;});

    //使用for_each输出各个元素, 送入一个Print实例
    std::for_each(v.begin(), v.end(), Print<int>{});
    // 利用lambda表达式：std::for_each(v.begin(), v.end(), [](int x){ cout << x << ' ';});
    //输出: 0 1 2 3 4 5 6 7 8 9
}


int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
