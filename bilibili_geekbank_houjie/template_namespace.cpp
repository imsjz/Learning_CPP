/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-13 17:02:11
 */
/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-13 17:02:11
 */
#include <iostream>
#include "template_namespace.h"

using namespace sanjay;


void test01(){
    //类模板, 需要显式指定模板数据类型
    complex<double> c1(2.5, 1.3);
    complex<int> c2(2, 6);

    std::cout << c1.real() << std::endl;
    std::cout << c2. imag() << std::endl;

    stone r1(2,3, 1), r2(2,3, 3), r3(0, 0, 0);
    //函数模板不需要显式指定模板数据类型, 编译器会进行参数类型推导
    r3 = min(r1, r2); //
    

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
