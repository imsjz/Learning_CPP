/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 15:28:06
 */
#include <iostream>
using namespace std;
class A{
    public:
        int i;
        int j;
        A(int n):i(n), j(n){}
};
int main(){
    A a(100);
    int &r = reinterpret_cast<int&>(a); //强行让r引用a
    //a站8个字节，前4个字节存放i，后4个字节存放j
    r = 200; //改变了i
    cout << a.i << "," << a.j << endl;
    int n = 300;
    A *pa = reinterpret_cast<A*>(&n); //强行让pa指向n
    pa->i = 400; //使n变为400
    pa->j = 500; //程序可能崩溃
    cout << n << endl;
    
    long long la = 0x12345678abcdLL;
    pa = reinterpret_cast<A*>(la); //la太长，而指针pa只有4个字节大小，因此将低32位0x5678abcd拷贝给pa
    unsigned int u = reinterpret_cast<unsigned int>(pa); //pa逐个比特拷贝到u
    cout << hex << u << endl;

    typedef void (* PF1)(int); //函数指针
    typedef int (* PF2)(int, char *); //函数指针
    PF1 pf1;
    PF2 pf2;
    pf2 = reinterpret_cast<PF2>(pf1); //两个不同类型的函数指针之间可以互相转换

    //##############################const_cast#####################33
    const string s = "Inception";
    string &p = const_cast<string&>(s);
    string *ps = const_cast<string*>(&s);

    return 0;
}