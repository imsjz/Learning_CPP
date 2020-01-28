#include <iostream>
#include <vector>
#include <map>

using namespace std;

//当map为形参时，如果传const，容易报错
int test(const map<int, int>& test_map, int i){
    //int a = test_map[i]; //原因在于[]是non-const的
    int a = test_map.at(i);
    const int& b = test_map.at(i);
    cout << b << endl;
    return a;
}

int main(int argc, char* argv[]){
    map<int, int> test_map;
    test_map[1] = 2;
    cout << test(test_map, 1) << endl;

    return 0;
}
