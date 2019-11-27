/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-27 17:42:39
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Base{
public:

};
void test01(){
    int myints[] = {10, 20, 30, 40, 50, 60, 70};
    vector<int> my_vec(7);
    copy(myints, myints + 7, my_vec.begin());

    for(auto e: my_vec){
        cout << e << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
