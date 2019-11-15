/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-13 21:17:50
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
    ifstream inFile("/home/sanjay/DATA/Learning_workspace/Learning_cpp/Coursera/week7/student.dat", ios::in | ios::binary);
    if(!inFile){
        cout << "error" << endl;
        return 0;
    }
    while(inFile.read((char *)&s, sizeof(s))){
        int nReadedBytes = inFile.gcount();//看看读了多少字节
        cout << s.szName << " " << s.nScore << endl;
        cout << "bytes: " << nReadedBytes << endl;
    }
    inFile.close();
    return 0;
}