#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    std::vector<int> vec;
    for(int i = 0; i < 10; ++i){
        vec.push_back(i);
    }
    for(auto ele : vec){
        std::cout << ele << " ";
    }
    std::cout << "\tvec.size() = " << vec.size() << std::endl;

    //clear
    vec.clear();
    std::cout << "after clear()" << std::endl;
    for(auto ele : vec){
        std::cout << ele << " ";
    }
    std::cout << "\tvec.size() = " << vec.size() << std::endl;


    return 0;
}