/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-23 19:30:53
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:

};
void test01(){
    //1. 不再允许字符串字面值常量赋值给一个 char *。如果需要用字符串字面值常量赋值和初始化一个 char *，应该使用 const char * 或者 auto。
    const char* str = "hello world";
    //2. C++98 异常说明、 unexcepted_handler、set_unexpected() 等相关特性被弃用，应该使用 noexcept。
    //3.auto_ptr 被弃用，应使用 unique_ptr
    //4. register 关键字被弃用
    //5. bool 类型的 ++ 操作被弃用
    // bool b = false;
    //6. C 语言风格的类型转换被弃用，应该使用 static_cast、reinterpret_cast、const_cast 来进行类型转换
    
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
