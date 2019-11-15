/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-16 10:00:42
 */
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
class A{    //定义类A，并与友元重载<, ==, 和<<
    private:
        int n;
    public:
        A(int n_) {n = n_;}
        friend bool operator<(const A &a1, const A &a2);
        friend bool operator==(const A &a1, const A &a2);
        friend ostream& operator<<(ostream &o, const A &a);
};
bool operator<(const A &a1, const A &a2){
    return a1.n < a2.n;
}
bool operator==(const A &a1, const A &a2){
    return a1.n == a2.n;
}
ostream& operator<<(ostream &o, const A &a){
    o << a.n;
    return o;
}

//定义函数模板PrintList，打印列表中的对象
template<class T>
void PrintList(const list<T> &lst){
    int tmp = lst.size();
    if(tmp > 0){
        typename list<T>::const_iterator i;
        i = lst.begin();
        for (i = lst.begin(); i != lst.end(); i++)
            cout << *i << ",";
    }
}

int main(){
    list<A> lst1, lst2;
    lst1.push_back(1); lst1.push_back(3);
    lst1.push_back(2); lst1.push_back(4); lst1.push_back(2);
    //lst1: 1 3 2 4 2
    lst2.push_back(10); lst2.push_front(20);
    lst2.push_back(30); lst2.push_front(40); lst2.push_back(40);
    //lst2: 40 20 10 30 40
    cout << "1)"; PrintList(lst1); cout << endl;
    cout << "2)"; PrintList(lst2); cout << endl;
    lst2.sort(); // 10 20 30 40 40
    cout << "3)"; PrintList(lst2); cout << endl;

    lst2.pop_front();
    cout << "4)"; PrintList(lst2); cout << endl; //lst2: 20 30 40 40

    lst1.remove(2); //删除所有和A(2)相等的元素
    cout << "5)"; PrintList(lst1); cout << endl; // 1 3 4

    lst2.unique();//删除所有和前一个元素相等的元素
    cout << "6)"; PrintList(lst2); cout << endl; //20 30 40

    lst1.merge(lst2); //合并lst2刀lst1并清除lst2
    cout << "7)"; PrintList(lst1); cout << endl; // 1 3 4 20 30 40
    cout << "8)"; PrintList(lst2); cout << endl; // 

    lst1.reverse(); //逆序
    cout << "9)"; PrintList(lst1); cout << endl; //40 30 20 4 3 1

    lst2.push_back(100); lst2.push_back(200);
    lst2.push_back(300); lst2.push_back(400); // lst2: 100 200 300 400
    list<A>::iterator p1, p2, p3;

    p1 = find(lst1.begin(), lst1.end(), 3);
    p2 = find(lst2.begin(), lst2.end(), 200);
    p3 = find(lst2.begin(), lst2.end(), 400);
    lst1.splice(p1, lst2, p2, p3); //将[p2, p3)插入p1前面，并从lst2中删除[p2, p3)
    //lst1: 40 30 20 4 200 300 3 1
    //lst2: 100 400

    cout << "10)"; PrintList(lst1); cout << endl;
    cout << "11)"; PrintList(lst2); cout << endl;


    return 0;
}
