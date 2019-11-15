/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-12 14:12:06
 */
#include <iostream>
#include <string>
using namespace std;

class CStudent{
    private:
        string name;
        string id;
        char gender;
        int age;
    public:
        void PrintInfo();
        void SetInfo(const string &name_, const string &id_,
            int age_, char gender_);
        string GetName(){return name;}
};
//继承类
class CUndergraduateStudent: public CStudent{
    private:
        string department;
    public:
        void QualifiedForBaoyan(){
            cout << "Qualified for baoyao" << endl;
        }
        void PrintInfo(){
            CStudent::PrintInfo();
            cout << "Department: " << department << endl;
        }
        void SetInfo(const string &name_, const string &id_,
            int age_, char gender_, const string &department_){
                CStudent::SetInfo(name_, id_, age_, gender_);
                department = department_;
            }
};

void CStudent::PrintInfo(){
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
}
void CStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_){
    name = name_;
    id = id_;
    age = age_;
    gender = gender_;
}

int main(){
    CUndergraduateStudent s2;
    s2.SetInfo("Harry Potter", "1113432412", 25, 'M', "Computer Science");
    cout << s2.GetName() << endl;
    s2.QualifiedForBaoyan();
    s2.PrintInfo();
    return 0;
}