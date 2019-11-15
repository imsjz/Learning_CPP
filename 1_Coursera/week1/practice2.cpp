/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-06-27 20:49:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
class CStudent{
    private:
        string name;
        string stuNum;
        unsigned short age;
        unsigned short firstGrade;
        unsigned short secondGrade;
        unsigned short thirdGrade;
        unsigned short fourthGrade;
    public:
        CStudent(string name, unsigned short age, string stuNum, unsigned short
                first, unsigned short second, unsigned short third, unsigned
                short fourth):
            name(name), age(age), stuNum(stuNum), firstGrade(first), secondGrade(second),
            thirdGrade(third), fourthGrade(fourth){}
        void printStuMessage(void){
            cout << name << "," << age << "," << stuNum << "," <<
                (int)((firstGrade + secondGrade + thirdGrade + fourthGrade) / 4)
                << endl;
        }

};

int main(int argc, char* argv[]){
    vector<string> info;
    string input;
    cout <<
        "请输入姓名，年龄，学号，第一年平均成绩，第二年平均成绩，第三年和第四年的平均成绩，各部分内容以\",\"隔开，不要空格"
        << endl;
    cin >> input;
    //创建一个流对象
    stringstream sstr(input);
    string token;
    while(getline(sstr, token, ',')){
        info.push_back(token);
    }
    //这时候info的后四个就是成绩了。

    //cout << atoi(info[3].c_str()) << endl;
    string name = info[0];
    unsigned short age = (unsigned short)atoi(info[1].c_str());
    cout << typeid(info[1]).name() << endl;
    string stuNum = info[2];
    unsigned short first = (unsigned short)atoi(info[3].c_str());
    unsigned short second = (unsigned short)atoi(info[4].c_str());
    unsigned short third = (unsigned short)atoi(info[5].c_str());
    unsigned short fourth = (unsigned short)atoi(info[6].c_str());
    CStudent student = CStudent(name, age, stuNum, first, second, third,
            fourth);
    student.printStuMessage();

    return 0;
}
