/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-25 18:54:37
 */
//---------------------------------------------------
#include <iostream>   // std::cout
#include <functional> // std::minus
#include <numeric>    // std::accumulate
using namespace std;
namespace sanjay
{
int myfunc(int x, int y)//函数版本
{
    return x + 2 * y;
}

struct myclass
{
    int operator()(int x, int y) { return x + 3 * y; }
} myobj;//仿函数版本

void test_accumulate()
{
    cout << "\ntest_accumulate().......... \n";
    int init = 100;
    int nums[] = {10, 20, 30};

    cout << "using default accumulate: ";
    cout << accumulate(nums, nums + 3, init); //100+ 10 + 20+ 30 = 160
    cout << '\n';

    cout << "using functional's minus: ";
    cout << accumulate(nums, nums + 3, init, minus<int>()); //100 - 10 - 20 - 30 = 40
    cout << endl;

    cout << "using custom function: ";
    cout << accumulate(nums, nums + 3, init, myfunc); //100 + 20 + 40 + 60 = 220
    cout << '\n';

    cout << "using custom object: ";
    cout << accumulate(nums, nums + 3, init, myobj); //280 = 100 + 30 + 60 + 90 =280 
    cout << '\n';
}
} // namespace sanjay

int main(){
    sanjay::test_accumulate();

    return 0;
}