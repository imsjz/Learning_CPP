/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-21 18:57:25
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
class LessThen9{
    public:
        bool operator()(int n){return n < 9;}
};
void outputSquare(int value){cout << value * value << " ";}
int calculateCube(int value){ return value * value * value;}

int main(){
    const int SIZE = 10;
    int a1[] = {1,2,3,4,5,6,7,8,9,10};
    int a2[] = {100, 2, 8, 1, 50, 3, 8, 9, 10, 2};
    vector<int> v(a1, a1+SIZE);
    ostream_iterator<int> output(cout, " ");
    random_shuffle(v.begin(), v.end());
    cout << endl << "1)";
    copy(v.begin(), v.end(), output);
    copy(a2, a2+SIZE, v.begin()); //v现在存储的是a2的内容了
    cout << endl << "2)";
    cout << count(v.begin(), v.end(), 8);
    cout << endl << "3)";
    cout << count_if(v.begin(), v.end(), LessThen9());//6
    cout << endl << "4)";
    cout << *(min_element(v.begin(), v.end())); //1
    cout << endl << "5)";
    cout << *(max_element(v.begin(), v.end())); //100
    cout << endl << "6)";
    cout << accumulate(v.begin(), v.end(), 0); //193

    cout << endl << "7)";
    for_each(v.begin(), v.end(), outputSquare);
    vector<int> cubes(SIZE);
    transform(a1, a1+SIZE, cubes.begin(), calculateCube);
    cout << endl << "8)";
    copy(cubes.begin(), cubes.end(), output);

    return 0;
}