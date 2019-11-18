/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 20:21:32
 */
#include <iostream>

using namespace std;


//常量转换 const_cast
void test01(){
    const int *p = NULL;
    //去除const
    int *new_p = const_cast<int*>(p);

    //加入const
    int *p2 = NULL;
    const int *new_p2 = const_cast<const int*>(p2);

    //不能对非指针   或者 非引用的变量 进行转换
    // const int a = 10;
    // int b = const_cast<int>(a); //a和b的存储位置都不一样

    //引用
    int num = 20;
    int &num_ref = num;

    //引用转为常引用
    const int &const_num_ref = const_cast<const int&>(num_ref);
}

class Base{};
class Other{};

//重新解释转换reinterpret_cast
void test02(){
    int a = 10;
    int *p = reinterpret_cast<int*>(a);

    Base *base = NULL;
    Other *other = reinterpret_cast<Other*>(base);

}
int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
