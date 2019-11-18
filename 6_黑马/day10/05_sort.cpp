/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 13:33:35
 */
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>


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

//排序规则
bool Compare(int v1, int v2){
    return v1 > v2;
}

void test01(){
    //排序 sort
    deque<int> d;
    d.push_back(2);
    d.push_back(1);
    d.push_back(53);
    d.push_back(23);

    sort(d.begin(), d.end());
    PrintDeque(d);

    sort(d.begin(), d.end(), Compare);
    PrintDeque(d);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
