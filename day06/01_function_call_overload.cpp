/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 15:04:50
 */
#include <iostream>
#include <string>

using namespace std;

class MyPrint{
public:

    void operator()(string text){
        cout << text << endl;
    }
};

void test01(){

    MyPrint my_print;
    my_print("hello world"); //仿函数

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
