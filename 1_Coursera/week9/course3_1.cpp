/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-21 14:11:59
 */
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<double> priorities;
    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);
    while(!priorities.empty()){
        cout << priorities.top() << " ";
        priorities.pop();
    }
    cout << endl;
    exit(0);
}