/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 10:14:16
 */
#include <iostream>

using namespace std;

class MyInteger{
public:
    MyInteger(){
        num_ = 0;
    }


    //为什么要返回引用，因为：int a = 10; cout << ++(++a) << endl ; cout << a << endl; 最后a是等于12的
    //如果不返回引用， MyInteger my_int; cout << ++(++my_int) << endl; cout << my_int << endl; 最后my_int是等于1
    //前置++代码
    MyInteger& operator++(){                //不能从形式上看，要从结果去看，形式上是：a++;没用 //从结果去看，只要在里面完成前置的工作即可
        this->num_++;
        return *this;
    }
    //后置++代码,加个int，是为了形式上的匹配
    MyInteger operator++(int){
        //先保存目前数据
        MyInteger tmp = *this;
        this->num_++;
        return tmp;
    }

    friend ostream& operator<<(ostream &os, const MyInteger &my_int);

    int num_;
};

ostream& operator<<(ostream &os, const MyInteger &my_int){
    os << my_int.num_;
    return os;
}

void test01(){

    MyInteger my_integer;
    ++my_integer; //1
    cout << my_integer++ << endl; //输出1
    // cout << ++my_integer << endl;
    cout << my_integer << endl; //输出2
    

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
