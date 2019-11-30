/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-30 12:23:26
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

void print(){

}
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args){
    cout << firstArg << endl;
    print(args...);
    //使用sizeof...查看变参大小
    cout << sizeof...(args) << endl;
}

//模仿tuple的构造方式来弄个例子
template<typename... Values> class Base; //声明base是类模板
//两个泛华
template<>
class Base<>{

};
template<typename Head, typename... Tail>
class Base<Head, Tail...> 
: private Base<Tail...>{
    typedef Base<Tail...> inherited;
public:
    Base(){}
    Base(Head v, Tail... vtail):m_head(v), inherited(vtail...){
    }
    Head head() { return m_head;}
    inherited& tail() {return *this;}

protected:
    Head m_head;
};

int main(int argc, char *argv[]){
    // print(7.5, "hello", bitset<16>(377), 43);
    Base<int, float, string> b(41, 6.3, "nico");
    cout << b.head() << endl;
    cout << b.tail().head() << endl; //6.3
    

    return 0;
}
