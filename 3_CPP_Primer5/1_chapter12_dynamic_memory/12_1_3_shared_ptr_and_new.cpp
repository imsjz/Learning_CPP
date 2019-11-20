#include <iostream>
#include <memory>
using namespace std;

int main(){
    shared_ptr<double> p1;
    shared_ptr<int> p2(new int(32)); //使用new来对shared_ptr进行初始化
    
    //只能直接初始化，不能进行隐式转换
    //shared_ptr<int> p1 = new int(32); //error
    shared_ptr<int> p2(new int(1024));
}

shared_ptr<int> clone(int p){
    return shared_ptr<int>(new int(p));
}