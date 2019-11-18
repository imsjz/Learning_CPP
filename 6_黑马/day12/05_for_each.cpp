/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-25 17:27:48
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Print{

    void operator()(int val){
        cout << val << endl;
        ++count_;
    }

    int count_;
};

/* 

遍历算法 遍历容器元素 

@param beg 开始迭代器 

@param end 结束迭代器 

@param _callback  函数回调或者函数对象 

@return 函数对象 

*/ 

//for_each(iterator beg, iterator end, _callback); 

void test01(){
    //用法1: 遍历
    //用法2: 保存内部状态
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    Print my_print = for_each(v.begin(), v.end(), Print());
    cout << "打印次数: " << endl;
    cout << my_print.count_ << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
