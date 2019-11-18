#include <iostream>
using namespace std;
#define DEBUG

#define MIN(a,b) (a<b ? a:b)

int main(){
    int i, j;
    i = 100;
    j = 20;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
    /* 这是注释部分*/
    cout << "随便些什么" << endl;
#endif

    cout << "The min value is: " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif
    return 0;
}
