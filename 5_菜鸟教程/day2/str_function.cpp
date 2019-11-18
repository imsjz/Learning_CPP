#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str1[11] = "Hello";
    char str2[11] = "world";
    char str3[11];
    int len;

    //copy str1 to str3
    strcpy(str3, str1);
    cout << "strcpy(str3, str1): " << str3 << endl;


    //concatenate str1 and str2
    strcat(str1, str2);
    cout << "strcat(str1, str2): " << str1 << endl;

    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;

    return 0;

}
