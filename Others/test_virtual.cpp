/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-11 15:34:16
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:
    virtual ~Base();
};
void test01(){
    cout << sizeof(Base) << endl;
    cout << sizeof(long) << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
