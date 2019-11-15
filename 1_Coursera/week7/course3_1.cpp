/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-14 11:01:19
 */
#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair{
    public:
        T1 key;
        T2 value;
        Pair(T1 k, T2 v):key(k),value(v){}
        bool operator<(const Pair<T1, T2> &p) const;
};

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const{
    return key < p.key;
}

int main(){
    Pair<string, int> student("Tom", 19);
    cout << student.key << " " << student.value << endl;
    return 0;
}