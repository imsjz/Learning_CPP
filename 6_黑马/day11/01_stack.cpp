/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 16:22:43
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Base{
public:

};
void test01(){
    stack<int> s;
    //放入数据push
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty()){
        cout << "栈顶元素为: " << s.top() << endl;
        //弹出栈顶元素
        s.pop();
    }
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
