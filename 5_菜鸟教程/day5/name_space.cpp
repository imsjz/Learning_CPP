#include <iostream>
using namespace std;

//第一个命名空间
namespace first_space{
    void func(){
        cout << "Inside first_space" << endl;
    }
}

namespace second_space{
    void func(){
        cout << "Inside second_space" << endl;
    }
}

int main(){
    first_space::func();

    second_space::func();
    return 0;
}

