/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-25 22:18:04
 */
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std::placeholders;
using namespace std;

double my_divide(double x, double y){
    return x / y;
}

struct MyPair{
    double a, b;
    double multiply(){
        return a * b;
    }
};

int main(){
    auto fn_five = bind(my_divide, 10, 2);
    cout << fn_five() << endl; //5

    auto fn_half = bind(my_divide, _1, 2);
    cout << fn_half(10) << endl; //5

    auto fn_invert = bind(my_divide, _2, _1);
    cout << fn_invert(10, 2) << endl; //0.2

    auto fn_rounding = bind<int> (my_divide, _1, _2);
    cout << fn_rounding(10, 3) << endl; //3

    // 以上是绑定函数, 下面是绑定成员
    MyPair ten_two {10, 2}; //直接给a, b赋值了

    auto bound_memfn = bind(&MyPair::multiply, _1);
    cout << bound_memfn(ten_two) << endl; // 20

    auto bound_memdata = bind(&MyPair::a, ten_two);
    cout << bound_memdata() << endl; //10

    auto bound_memdata2 = bind(&MyPair::b, _1);
    cout << bound_memdata2(ten_two) << endl; //2`

    vector<int> v{15, 37, 94, 50, 73, 58, 28, 98};
    int n = count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 50)));
    cout << "n = " << n << endl; //n = 5

    auto fn_ = bind(less<int>(), _1, 50);
    cout << count_if(v.cbegin(), v.cend(), fn_) << endl; //3
    cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50)) << endl; //3

    return 0;
}