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
using namespace first_space;

int main(){

    func();
    return 0;
}

