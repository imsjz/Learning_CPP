#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
   vector<int> vec;
   for(int i = 0; i < 10; ++i){
       vec.push_back(i);
   }
    for(int i = 0; i < 10; ++i){
        cout << &vec[i] << endl;
    }

    cout << "============" << endl;
    vector<int>* p_vec = &vec;
    for(int i = 0; i < 10; ++i){
        cout << &(*p_vec)[i] << endl;
    }
   return 0;
}
