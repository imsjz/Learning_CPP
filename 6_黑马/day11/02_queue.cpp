/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 17:31:43
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Base{
public:

};
void test01(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(65);

    while(!q.empty()){
        cout << "队头: " << q.front() << endl;
        cout << "队尾: " << q.back() << endl;
        //弹出队头元素
        q.pop();
    }
    cout << "size: " << q.size() << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
