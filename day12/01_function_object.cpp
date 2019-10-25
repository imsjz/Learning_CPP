/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-24 21:42:14
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base{
public:
    void operator()(int num){
        cout << num << endl;
        count_++;
    }
    int count_ = 0;
};
void test01(){
    Base base;
    base(111);

    Base()(222);
}

//函数对象超出普通函数概念, 内部可以保存状态
void test02(){
    Base base;
    base(1000);
    base(1000);
    base(1000);
    base(1000);
    base(1000);
    base(1000);
    cout << base.count_ << endl;
}

//函数对象作为参数
void DoPrint(Base base, int num){
    base(num);
}
void test03(){
    DoPrint(Base(), 4342);
}

int main(int argc, char *argv[]){
    // test01();
    // test02();
    test03();

    return 0;
}
