/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-22 19:49:43
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <string.h>

using namespace std;

class Base{
public:

};
void test01(){
    //stack和queue都不支持遍历, 不提供iterator
    //stack<string>::iterator ite; //has no member
    //queue<string>::iterator ite; //
    stack<string, list<string>> c;
    char buf[10];
    for(long i = 0; i < 10; ++i){
        snprintf(buf, 10, "%d", rand());
        c.push(string(buf));
    }
    cout << "stack.size() " << c.size() << endl;
    cout << "stack.top() " << c.top() << endl;
    c.pop();
    cout << "stack.size() " << c.size() << endl;
    cout << "stack.top() " << c.top() << endl;
    
    cout << "=====================华丽的分割线==================================" << endl;

    memset(buf, 0, 10);
    queue<string, list<string>> q;
    for(long i = 0; i < 10; ++i){
        snprintf(buf, 10, "%d", rand());
        q.push(string(buf));
    }
    cout << "queue.size() " << q.size() << endl;
    cout << "queue.front() " << q.front() << endl;
    cout << "queue.back() " << q.back() << endl;
    q.pop();
    cout << "queue.size()" << q.size() << endl;
    cout << "queue.front() " << q.front() << endl;
    cout << "queue.back() " << q.back() << endl;

}
void test02(){
    //stack和queue都不支持遍历, 不提供iterator
    //stack<string>::iterator ite; //has no member
    //queue<string>::iterator ite; //
    stack<string, vector<string>> c;
    char buf[10];
    for(long i = 0; i < 10; ++i){
        snprintf(buf, 10, "%d", rand());
        c.push(string(buf));
    }
    cout << "stack.size() " << c.size() << endl;
    cout << "stack.top() " << c.top() << endl;
    c.pop();
    cout << "stack.size() " << c.size() << endl;
    cout << "stack.top() " << c.top() << endl;
    
    cout << "=====================华丽的分割线==================================" << endl;

    memset(buf, 0, 10);
    queue<string, vector<string>> q;
    for(long i = 0; i < 10; ++i){
        snprintf(buf, 10, "%d", rand());
        q.push(string(buf));
    }
    cout << "queue.size() " << q.size() << endl;
    cout << "queue.front() " << q.front() << endl;
    cout << "queue.back() " << q.back() << endl;
    q.pop();
    cout << "queue.size()" << q.size() << endl;
    cout << "queue.front() " << q.front() << endl;
    cout << "queue.back() " << q.back() << endl;

}
int main(int argc, char *argv[]){
    //test01();
    test02();

    return 0;
}
