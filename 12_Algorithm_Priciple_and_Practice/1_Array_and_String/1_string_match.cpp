/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-07 16:39:17
 */
/*
* Returns the position of the first occurrence of string target in
string source, or -1 if target is not part of source.

*/
#include <iostream>
using namespace std;

/* brute-force方法 */
char* SubStr(const char* source, const char* target){
    //判断异常
    if(!*target){
        return (char*)source;
    }
    char* p1 = (char*)source;
    while(*p1){
        char* p1Begin = p1;
        char* p2 = (char*)target;
        while(*p1 && *p2 && *p1 == *p2){
            ++p1;
            ++p2;
        }
        if(!*p2){
            return p1Begin;
        }
        p1 = p1Begin + 1;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    // const char* str = "hell";
    // char* nonconst_str = (char*)str;

    // /*
    // 地址是一样的
    // */
    // cout << (long)str << endl;
    // cout << (long)nonconst_str << endl;

    const char* source = "hello";
    const char* target = "ol";
    char* result = SubStr(source, target);
    cout << result << endl;


    return 0;
}
