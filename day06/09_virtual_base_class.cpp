/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-15 09:43:24
 */
#include <iostream>

using namespace std;

class Animal{
public:
    int age_;
};

//虚基类 会产生一个虚基类表
//操作的是一份共享的数据
class Sheep: virtual public Animal{
public:

};

class Tuo : virtual public Animal{
public:

};

class SheepTuo : public Sheep, public Tuo{

};
void test01(){
    cout << sizeof(SheepTuo) << endl; //8
    SheepTuo sheep_tuo;
    sheep_tuo.Sheep::age_ = 10;
    sheep_tuo.Tuo::age_ = 20;

    cout << sheep_tuo.Sheep::age_ << endl;
    cout << sheep_tuo.Tuo::age_ << endl;

    cout << sheep_tuo.age_ << endl; //可以直接访问了,没有二义性了,因为只有一份数据了
}

//通过地址找到  偏移量
//内部工作原理
void test02(){
    SheepTuo st;
    st.age_ = 100;

    //找到Sheep的偏移量操作
    cout << *(long*)((long*)*(long*)&st + 1) << endl; //不知道对不对

    cout << "sizeof(int) " << sizeof(int) << endl;
    cout << "sizeof(long) " << sizeof(long) << endl;
    //找到Tuo的偏移量操作
    // cout << *((long*)((long*)*((long*)&st+1) + 1))<< endl; //不对

    //输出age_
    // cout << ((Animal*)((char*)&st + *(long*)((long*)*(long*)&st + 1)))->age_ << endl; //不对
}


int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
