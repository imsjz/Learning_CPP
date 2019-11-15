/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-10 19:06:52
 */
#include<iostream>
using namespace std;
class CStudent{
    public:
        int nAge;
};

ostream& operator<<(ostream &o, const CStudent &s){
    o << s.nAge;
    return o;
}

int main(){
    CStudent s;
    s.nAge = 5;
    cout << s << "age";
    return 0;
}
