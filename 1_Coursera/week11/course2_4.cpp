/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-22 21:40:55
 */
#include <iostream>
#include <regex>
using namespace std;
int main(){
    regex reg("b.?p.*k");
    cout << regex_match("bopggk", reg) << endl; //1
    cout << regex_match("boopgljk", reg) << endl; //0
    cout << regex_match("b pk", reg) << endl; //1
    regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
    string correct = "123Hello N/A Hello";
    string incorrect = "123Hello 12 hello";
    cout << regex_match(correct, reg2) << endl; //1
    cout << regex_match(incorrect, reg2) << endl; //0

    return 0;
}