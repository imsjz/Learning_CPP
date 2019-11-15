/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-13 21:27:59
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class CStudent{
    public:
        char szName[20]; //20bytes
        int nScore; //4bytes
};
int main(){
    CStudent s;
    fstream iofile("/home/sanjay/DATA/Learning_workspace/Learning_cpp/Coursera/week7/student.dat", ios::in | ios::out | ios::binary);
    if(!iofile){
        cout << "error " << endl;
        return 0;
    }
    iofile.seekp(2 * sizeof(s), ios::beg);
    iofile.write("Mike", strlen("Mike") + 1);
    iofile.seekg(0, ios::beg);
    while(iofile.read((char*)&s, sizeof(s))){
        cout << s.szName << " " << s.nScore << endl;
    }
    iofile.close();
    return 0;
}