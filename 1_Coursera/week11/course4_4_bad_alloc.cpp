/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-23 18:28:55
 */
#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
    try{
        char *p = new char[0xfffffffffffffff];
    }
    catch(bad_alloc e){
        cerr << e.what() << endl;
    }
    return 0;
}