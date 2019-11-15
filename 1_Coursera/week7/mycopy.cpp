/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-13 21:36:40
 */
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        cout << "File name missing!" << endl;
        return 0;
    }
    ifstream inFile(argv[1], ios::in | ios::binary);
    if(!inFile){
        cout << "Source file open error" << endl;
        return 0;
    }
    ofstream outFile(argv[2], ios::out | ios::binary);
    if(!outFile){
        cout << "new file open error" << endl;
        inFile.close();
        return 0;
    }
    char c;
    while(inFile.get(c))
        outFile.put(c);
    outFile.close();
    inFile.close();
    return 0;
}