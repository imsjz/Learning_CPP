#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max(T const& a, T const& b){
    return a < b? b: a;
}
int main(){
    int i = 38;
    int j = 45;
    cout << "Max(i,j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    return 0;
}
