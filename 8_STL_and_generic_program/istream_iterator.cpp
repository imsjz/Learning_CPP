/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-28 13:01:53
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

class Base{
public:

};
void test01(){
    double value1, value2;
    cout << "please, insert two values: " << endl;
    istream_iterator<double> eos;
    istream_iterator<double> iit(cin);

    if(iit != eos){
        value1 = *iit;
    }

    ++iit;
    if(iit != eos){
        value2 = *iit;
    }

    cout << "value1: " << value1 << ", " << "value2 : " << value2 << endl;
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
