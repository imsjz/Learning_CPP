/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-26 21:09:53
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <tuple>
#include <numeric>
#include <complex>

using namespace std;

class Base{
public:

};
void test01(){
    
    cout << "string, sizeof = " << sizeof(string) << endl; //32
    cout << "double, sizeof = " << sizeof(double) << endl; //8
    cout << "float, sizeof = " << sizeof(float) << endl; //4
    cout << "int, sizeof = " << sizeof(int) << endl;//4
    cout << "complex<double>, sizeof = " << sizeof(complex<double>) << endl;// 实数和虚数, 16
    
    //tuple
    tuple<string, int, int, complex<double>> t; //32 + 4 + 4 + 16 = 56
    cout << "sizeof = " << sizeof(t) << endl;


    //直接初始化
    tuple<int, float, string> t1(43, 23.1, "nico");
    cout << "tuple<int, float, string>, sizeof = " << sizeof(t1) << endl; //4 + 4 + 32 = 40
    //遍历各个元素
    cout << "t1: " << get<0>(t1) << ' ' << get<1>(t1) << ' ' << get<2>(t1) << endl;


    //用make_tuple创建
    auto t2 = make_tuple(22, 44, "stacy");

    //单个赋值
    get<1>(t1) = get<1>(t2);
    cout << "get<1>t1: " << get<1>(t1) << endl;

    //compare
    if(t1 < t2){
        cout << "t1 < t2" << endl;
    }
    else{
        cout << "t1 >= t2" << endl;
    }
    t1 = t2; //整体赋值
    //cout << "t1: " << t1 << endl;

    //另外一种赋值方式
    tuple<int, float, string> t3(77, 1.1, "more light");
    int i1;
    float f1;
    string s1;
    tie(i1, f1, s1) = t3;

    typedef tuple<int, float, string> TupleType;
    cout << tuple_size<TupleType>::value << endl; //3
    tuple_element<1, TupleType>::type f2 = 1.0;// 这种操作比较少用吧...


}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
