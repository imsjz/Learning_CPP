/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-22 09:48:09
 */
#include <iostream>
using std::cout;
using std::endl;

int main(){
    unsigned int a[] = {1,2,3,4};
    unsigned int* pd = a;

    printf("%d \t %d\n", *pd++, *pd++); //从右往左执行, 先执行*pd++, 因为*的优先级比++低, 因此先执行pd++, 然后*pd=1(因为是后置++), 接着执行下一个*pd++

    int b(10);
    ++++b;
    cout  << b << endl; //12
    //b++++; //error, 因为后置++返回的是值, 不是引用
    int i = 0;
    //cout << i++++ << endl;


    return 0;
}