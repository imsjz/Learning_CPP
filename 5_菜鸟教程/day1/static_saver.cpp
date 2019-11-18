#include <iostream>
using namespace std;

//declare function
void func(void);

static int count = 10; //global variable

int main(){
    
    while(count--){
        func();
    }
    return 0;
}

//function definition
void func(void){
    static int i = 5; //local static variable
    i++;
    cout << "变量i为 " << i ;
    cout << " , \t变量count为 " << count << endl;
}

