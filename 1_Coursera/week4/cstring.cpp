/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-08 17:01:29
 */
#include <iostream>
#include <cstring>
using namespace std;

class String{
    private:
        char *str;
    public:
        String():str(NULL){}
        const char *c_str(){return str;}
        void operator=(const char *s);
        ~String();
};

void String::operator=(const char *s){
    if(str) delete [] str;
    if(s){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
        str = NULL;
    //return str;
}

String::~String(){
    if(str) delete [] str;
}

int main(){
    String s;
    s = "good luck";
    cout << s.c_str() << endl;
    s = "shenzhou8";
    cout << s.c_str() << endl;
    return 0;
}