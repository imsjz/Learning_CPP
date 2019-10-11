/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 11:33:18
 */
#include <iostream>

using namespace std;

class MyString{

public:
    MyString(const char *str){

    }
    explicit MyString(int a){

    }

    char *m_str;
};

void test01(){

    MyString str = "abc";
    MyString str2(10);
    // MyString str3 = 10; //隐式类型转换, 等价于MyString str3 = Mystring(10);
    // //explicit关键字,防止隐式类型转换

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
