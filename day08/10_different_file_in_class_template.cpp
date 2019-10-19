/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 10:38:28
 */
#include <iostream>
#include "person.hpp"

//建议 模板不要做分文件编写, 写到一个类中即可. 类内进行声明和实现, 最后把后缀名改为.hpp   约定俗成的..

using namespace std;


int main(int argc, char const *argv[])
{
    Person<string, int> person("猪八戒" ,55);
    person.ShowPerson();
    return 0;
}
