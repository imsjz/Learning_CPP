/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2020-01-02 11:05:25
 */
#include <iostream>
#include <queue>

using namespace std;

void test01(){
    //优先队列，其实是二叉堆
    priority_queue<int> big_heap; //最大堆
    
    if(big_heap.empty()){
        cout << "big_heap is empty" << endl;
    }
    int test[] = {6, 10, 1, 7, 99, 4, 33};
    for(int i = 0; i < 7; ++i){
        big_heap.push(test[i]);
    }
    cout << "big_heap.top = " << big_heap.top() << endl;
    big_heap.push(1000);
    cout << "big_head.top = " << big_heap.top() << endl;
    for(int i = 0; i < 3; ++i){
        big_heap.pop();
    }
    cout << "big_heap.top = " << big_heap.top() << endl;
    cout << "big_heap.size() = " << big_heap.size() << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
