/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-22 14:41:12
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
    vector<int> v;
    cout << sizeof(v) << endl;//24 = 3 * 8
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
