/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-28 12:45:39
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iterator> //ostream_iterator

using namespace std;

void test01(){
    vector<int> my_vector;
    for(int i = 1; i < 10; ++i){
        my_vector.push_back(i*10);
    }
    ostream_iterator<int> out_it(cout, ",");
    copy(my_vector.begin(), my_vector.end(), out_it);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
