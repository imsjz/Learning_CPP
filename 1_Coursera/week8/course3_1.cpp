/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-15 21:18:56
 */
#include <iostream>
#include <vector>

int main(){
    int i;
    int a[5] = {1,2,3,4,5};
    std::vector<int> v(5);
    std::cout << v.end() - v.begin() << std::endl;
    for(i = 0; i < v.size(); ++i) v[i] = i;
    v.at(4) = 100;
    for(i = 0; i < v.size(); ++i)
        std::cout << v[i] << ",";
    std::cout << std::endl;
    std::vector<int> v2(a, a+5); //constructor function
    v2.insert(v2.begin() + 2, 13);
    for(i = 0; i < v2.size(); ++i)
        std::cout << v2.at(i) << ",";
    std::cout << std::endl;

    return 0;
}