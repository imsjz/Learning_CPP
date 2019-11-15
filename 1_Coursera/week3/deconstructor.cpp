#include <iostream>
using namespace std;

class Test{
    public:
        ~Test()
        {
            cout << "destructor called" << endl;
        }
};

int main(){
    Test array[2];
    cout << "End main" << endl;
    return 0;
}
