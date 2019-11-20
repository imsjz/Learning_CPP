/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-29 16:43:27
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int *pi = new int;
    int *p1 = new int(1024);
    string *p2 = new string(10, '0');
    //对vector动刀
    vector<int> *p3 = new vector<int>{1,2,3,4,5};
    //默认初始化
    string *p4 = new string; //p4指向空的string
    int *p5 = new int; //*p5的值未定义
    //值初始化
    string *p6 = new string(); //p6值初始化为空的string
    int *p7 = new int(); //*p7 为0
    cout << *p7 << endl;

    //自动推断auto
    int a = 3;
    string str = "hello";
    auto *p8 = new auto(a);
    auto *p9 = new auto(str);
    //####################delete###################
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    //delete i; //i 不是指针
    //delete pi1; //未定义
    delete pd;
    //delete pd2; //error
    delete pi2;
    //delete const 对象指针
    const int *pci = new const int(1024);
    delete pci;

    return 0;
}