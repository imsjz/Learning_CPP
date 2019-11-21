/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-21 16:16:58
 */
#include <vector>
#include <iostream>
#include <ext/pool_allocator.h>
using namespace std;
int main()
{
    vector<int, __gnu_cxx::__pool_alloc<int>> v = {1,2,3,4};
    for(auto e : v){
        cout << e << endl;
    }
    return 0;
}