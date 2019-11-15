/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-18 16:21:26
 */
#include <iostream>
#include <set>
using namespace std;
template<class T>
void Print(T first, T last){
    for(; first != last; ++first){
        cout << *first << " ";
    }
    cout << endl;
}
class A{
    private:
        int n;
    public:
        A(int n_) { n = n_;}
        friend bool operator<(const A &a1, const A &a2){ return a1.n < a2.n;}
        friend ostream& operator<<(ostream &o, const A &a){
            o << a.n;
            return o;
        }
        friend class MyLess;
};
struct MyLess{
    bool operator()(const A &a1, const A &a2){
        return (a1.n % 10) < (a2.n % 10);
    }
};
typedef multiset<A> MSET1;
typedef multiset<A, MyLess> MSET2;
int main(){
    const int SIZE = 6;
    A a[SIZE] = {4, 22, 19, 8, 33, 40};
    MSET1 m1;
    m1.insert(a, a + SIZE);
    m1.insert(22);
    cout << "1)" << m1.count(22) << endl; //2
    cout << "2)"; Print(m1.begin(), m1.end()); // 4 8 19 22 22 33 40

    MSET1::iterator pp = m1.find(19);
    if(pp != m1.end())
        cout << "found" << endl;
    cout << "3)"; cout << *m1.lower_bound(22) << ","
        << *m1.upper_bound(22) << endl; // 22 33
    
    pp = m1.erase(m1.lower_bound(22), m1.upper_bound(22)); //返回删除元素的后一个元素的迭代器
    cout << "4)"; Print(m1.begin(), m1.end()); // 4 8 19 33 40
    cout << "5)"; cout << *pp << endl; //33
    //##################################################
    MSET2 m2; //m2的元素按照个位数从小排到大
    m2.insert(a, a + SIZE);
    cout << "6)"; Print(m2.begin(), m2.end());

    return 0;
}