#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
struct myclass
{

    bool operator()(int i, int j) { return i < j; }

} myobj;//声明一个变量
void test01()
{
    vector<int> v{1,3,4,2,5,2};
    sort(v.begin(), v.end(), myobj);
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
