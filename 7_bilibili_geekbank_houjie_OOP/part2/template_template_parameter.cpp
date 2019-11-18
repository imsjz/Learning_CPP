/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-15 16:34:42
 */
#include <iostream>
#include <list>
using namespace std;

// namespace sanjay{

// template<typename T,
//         template <typename T>
//             class Container
//         >
// class XCls{

// public:
//     Container<T> c;
// public:
//     // ...
// };

// }

// template<typename T>
// using Lst = list<T, allocator<T>>;

// using namespace sanjay;

//==========================================

#include <memory>

namespace luke{

template<typename T1,
        template <typename T1>
            class SmartPtr
        >
class XCls{

private:
    SmartPtr<T1> sp;
public:
    // ...
    XCls() : sp(new T1){}
};

}



int main(){
    // XCls<string, list> mylst1;
    // XCls<string, Lst> mylst2;

    luke::XCls<string, shared_ptr> p1;
    // luke::XCls<string, auto_ptr> p2;


    return 0;
}