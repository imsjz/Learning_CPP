/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-13 21:10:25
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class CStudent{
    public:
        char szName[20];
        int nScore;
};
int main(){
    CStudent s;
    ofstream OutFile("/home/sanjay/DATA/Learning_workspace/Learning_cpp/Coursera/week7/student.dat", ios::out|ios::binary);
    while (cin >> s.szName >> s.nScore){
        if(strcmp(s.szName, "exit") == 0)
            break;
        OutFile.write((char *)&s, sizeof(s));
    }
    OutFile.close();
    return 0;
}