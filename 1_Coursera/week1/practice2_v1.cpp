/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-06-27 20:38:00
 */
#include <iostream>
#include <string.h>
using namespace std;

class CStudent{
private:
    // string name, number;
    char name[100], number[100];
    int age, avg_year1, avg_year2, avg_year3, avg_year4;

public:
    CStudent(char name_[100], int age_, char number_[100], int avg_year1_, int avg_year2_, int avg_year3_, int avg_year4_):
     age(age_),avg_year1(avg_year1_), avg_year2(avg_year2_), 
    avg_year3(avg_year3_), avg_year4(avg_year4_){
        strcpy(name, name_);
        strcpy(number, number_);
    }
    
    void Message(void){
        cout << name << "," << age << "," << number << "," << (int)((avg_year1 + avg_year2 + avg_year3 + avg_year4) / 4) << endl;
    }
};

int main(){
    // string name, number;
    //如果char *name, *number;就出错，为什么？
    char name[100], number[100];
    char k; //用来临时放",”的
    int age;
    int avg_year1, avg_year2, avg_year3, avg_year4;

    cin.getline(name, 100, ',');
    cin >> age >> k;
    cin.getline(number, 100, ',');
    cin >> avg_year1 >> k >> avg_year2 >> k >> avg_year3 >> k >> avg_year4;
    CStudent student(name, age, number, avg_year1, avg_year2, avg_year3, avg_year4);
    student.Message();
    return 0;
}