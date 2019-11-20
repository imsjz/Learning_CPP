/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-30 10:47:34
 */
#include <iostream>
#include <memory>
using namespace std;

size_t getsize();

int main(){
    int *pia1 = new int[getsize()];
    delete [] pia1;

    //别名
    typedef int arrT[42];
    int *p1 = new arrT; //不用方括号
    delete [] p1;

    //初始化
    int *pia = new int[10]; //未初始化
    int *pia2 = new int[10](); //值初始化
    string *psa = new string[2]; 
    string *psa2 = new string[2]();
    delete [] pia;
    delete [] pia2;
    delete [] psa;
    delete [] psa2;
    //c++还可以用花括号初始化
    int *pia3 = new int[3]{1,2,3};
    string *psa3 = new string[3]{"hello", "world", "!"};
    delete [] pia3;
    delete [] psa3;

    //可以动态分配空数组
    //char arr[0];
    size_t n = getsize(); //n = 0
    int *p = new int[n];
    for(int *q = p; q != p + n; ++q)
        cout << "some thing" << endl;

    //智能指针与动态数组
    unique_ptr<int[]> up(new int[10]);
    
    //可以用下标运算符
    for(size_t i = 0; i != 10; ++i)
        up[i] = i;
    up.release(); //会调用delete[]

    //allocator类
    int t = 10;
    allocator<string> alloc;//创建一个对象
    auto const pat = alloc.allocate(t); //分配n个空间内存，但未初始化,p指向最后构造的元素位置之后的一个位置
    auto q = pat;
    alloc.construct(q++);//空字符串
    alloc.construct(q++, 3, 'c'); //3个c
    alloc.construct(q++, "hi");

    cout << *pat << endl; //空字符串
    //cout << *q << endl; //错误，指向未构造的内存
    //释放内存
    while(q != pat)
        alloc.destroy(--q); //释放已经构造的string
    alloc.deallocate(pat, t); //将分配的内存还给系统


    return 0;
}

size_t getsize(){
    return 0;
}