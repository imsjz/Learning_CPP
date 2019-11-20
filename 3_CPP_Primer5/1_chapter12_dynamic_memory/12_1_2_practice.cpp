/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-29 17:44:34
 */
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//#############################使用new 和 delele的版本###########################
vector<int>* alloc_vector(){
    vector<int> *p = new (nothrow) vector<int>;
    return p;
}

void read_ints(vector<int> *pv){
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        pv->push_back(num);
    }

}
void print_ints(vector<int> *pv){
    for(const auto &v: *pv)
        cout << v << " ";
    cout << endl;
}
//##############################是用shared_ptr的版本#################
shared_ptr<vector<int> > new_vector(){
    shared_ptr<vector<int> > p = make_shared<vector<int>>();
    return p;
}
void read_ints(shared_ptr<vector<int> > sp){
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        sp->push_back(num);
    }
}
void print_ints(shared_ptr<vector<int>> sp){
    for(const auto &v: *sp)
        cout << v << " ";
    cout << endl;
}


int main(){
    vector<int> *pv = alloc_vector(); //p是动态分配的内存
    if(!pv){
        cout << "内存不足" << endl;
        return -1;
    }
    read_ints(pv);
    print_ints(pv);
    delete pv;
    pv = nullptr;
    cout << endl << "shared_ptr版本" << endl;
    shared_ptr<vector<int>> sp = new_vector();
    read_ints(sp);
    print_ints(sp);
    return 0;
}