/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-12 10:20:26
 */
#include <iostream>

using namespace std;

class Person{
public:
    void show(){
        cout << "person show" << endl;
    }
    void showAge(){
        if(this == NULL){
            return;
        }
        cout << this->age << endl;
    }
    int age;
};

void test01(){

    Person *p = NULL;
    // p->show(); //可以访问
    p->showAge();

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
