#include <iostream>
using namespace std;

#define MIN(a,b) (a<b ? a:b)

int main(){
    int i, j;
    i = 100;
    j = 20;
    cout << "The min value is: " << MIN(i, j) << endl;
    return 0;
}
