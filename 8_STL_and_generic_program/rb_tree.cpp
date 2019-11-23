#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:

};
void test01(){
    //测试rb_tree
    _Rb_tree<int, int, _Identity<int>, less<int>> itree;
    cout << itree.empty() << endl; //1
    cout << itree.size() << endl; //0

    itree._M_insert_unique(3);
    itree._M_insert_unique(8);
    itree._M_insert_unique(5);
    itree._M_insert_unique(9);
    itree._M_insert_unique(13);
    itree._M_insert_unique(5);//unique不插入重复的
    cout << itree.empty() << endl; //0 
    cout << itree.size() << endl; // 5
    cout << itree.count(5) << endl; //1

    itree._M_insert_equal(5);
    itree._M_insert_equal(5);

    cout << itree.size() << endl; //7
    cout << itree.count(5) << endl; // 3
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
