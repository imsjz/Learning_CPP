/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-13 17:53:06
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

template <typename T>
class MyAlloc{
public:
    void operator()(){

    }
};

void test01(){
    vector<int> a;
    for(int i = 0; i < 10; ++i){
        a.push_back(i);
        cout << a.size() << endl;
        cout << a.capacity() << endl;
        cout << "============" << endl;
    }
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
