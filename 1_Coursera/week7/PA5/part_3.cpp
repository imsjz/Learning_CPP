/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-15 20:26:28
 * 利用流操纵算子实现： 输入一个整数，先将该整数以十六进制输出，然后再将该整数以10个字符的宽度输出，宽度不足时在左边补0。
 */
#include <iostream>


int main(){
    int a;
    std::cin >> a;

    //设置为十六进制
    std::cout.setf(std::cout.hex, std::cout.basefield);
    std::cout <<  a << std::endl;

    //设置为十进制
    std::cout.setf(std::cout.dec, std::cout.basefield);
    std::cout.fill('0');
    std::cout.width(10);
    std::cout << std::dec << a << std::endl;

    return 0;

}