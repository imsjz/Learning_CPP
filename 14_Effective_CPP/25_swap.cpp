/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-24 17:26:07
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


template <typename T>
class WidgetImpl{
public:

};

template<typename T>
class Widget{
public:

};

// namespace std
// {
//     //############################################//
//     //################   不合法：function template 不允许偏特化，只允许对类模型进行偏特化   ####################//
//     // 但是两者都可以特化
//     //############################################//
//     template<typename T>
//     void swap< Widget<T>>(Widget<T>& a, Widget<T>& b){
//         a.swap(b);
//     }
// } // namespace std

//上诉不行，采用重载的方法试试
namespace std
{
    template<typename T>
    void swap(Widget<T>& a, Widget<T>&b){
        // a.swap(b);
    }
} // namespace std
//这样的方法也不行，因为std不允许你加入新的东西。或者说是不建议。
//因此建议的方法是，把上诉swap的函数模型放在别的命名空间下。





class Base{
public:

};
void test01(){
    Widget<int> a, b;
    std::swap(a, b);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
