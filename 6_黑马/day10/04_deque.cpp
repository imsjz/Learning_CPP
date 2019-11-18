/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 12:18:17
 */
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

class Base{
public:

};

void PrintDeque(const deque<int> &dq){
    for(deque<int>::const_iterator cit = dq.cbegin(); cit != dq.cend(); ++cit){
        cout << *cit << " ";
        // (*cit) = 100;
    }
    cout << endl;
}

void test01(){
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    PrintDeque(d);

    deque<int> d2(d.begin(), d.end());
    d2.push_back(1000);
    PrintDeque(d2);

    //删除头尾
    d2.pop_back();
    d2.pop_front();
    PrintDeque(d2);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
