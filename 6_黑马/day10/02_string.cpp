/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-21 21:07:48
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Base{
public:

};
void test01(){
    //默认构造
    string str;
    string str2(str); //拷贝构造
    string str3 = str;

    string str4 = "abcd";
    string str5(5, 'a');

    cout << str4 << endl;
    cout << str5 << endl;
}

// string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串 
// string& operator=(const string &s);//把字符串s赋给当前的字符串 
// string& operator=(char c);//字符赋值给当前的字符串 
// string& assign(const char *s);//把字符串s赋给当前的字符串 
// string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串 
// string& assign(const string &s);//把字符串s赋给当前字符串 
// string& assign(int n, char c);//用n个字符c赋给当前字符串 
// string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串 

void test02(){
    string str;
    string str2;
    //基本赋值
    str = "hello";
    str2 = str;

    // string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
    string str3;
    str3.assign("abcdef", 3);
    cout << str3 << endl;
}

//字符串存取
void test03(){
    string s = "hello world";
    for(int i = 0; i < s.size(); ++i){
        // cout << s[i] << endl;
        cout << s.at(i) << endl;
    }
    //[] 和 at的区别? [] 访问越界, 直接挂掉 at会抛出异常
    try{
        // cout << s[100] << endl;
        cout << s.at(100) << endl;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }
    catch(...){
        cout << "越界异常" << endl;
    }
}



void test04(){
    string s1 = "he";
    s1 += "he";
    cout << s1 << endl;
    string s2 = "大佬";
    s1 += s2;
    cout << s1 << endl;
    s1 += 'a';
    cout << s1 << endl;

}

/*
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找 

int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找 

int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置 

int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置 

int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找 

int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找 

int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置 

int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置 

string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str 

string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s 
*/

void test05(){
    //find 查找
    //int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找 
    string s = "abcdfef";
    int pos = s.find("bcf"); //找不到返回-1
    cout << pos << endl;

    int pos2 = s.rfind("bc");
    cout << pos2 << endl;

    //string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str 
    string str = "hello";
    str.replace(1, 3, "kuk");
    cout << str << endl;

}

/* 

compare函数在>时返回 1，<时返回 -1，==时返回 0。 

比较区分大小写，比较时参考字典顺序，排越前面的越小。 

大写的A比小写的a小。 

*/ 

// int compare(const string &s) const;//与字符串s比较 

// int compare(const char *s) const;//与字符串s比较 

void test06(){
    string s1 = "Bbc";
    string s2 = "abc";
    if(s1.compare(s2) == 0){
        cout << "s1 = s2 " << endl;
    }
    else if(s1.compare(s2) == 1){
        cout << "s1 大于 s2" << endl;
    }
    else{
        cout << "s1 < s2" << endl;
    }
}

void test07(){
    //string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

    string str = "abcdef";

    string s2 = str.substr(1, 3); //bcd
    cout << s2 << endl;

    //需求 查找一个邮件的用户名
    string email_str = "sanjayzzzhong@gmail.com";

    int pos = email_str.find("@");

    string email_name = email_str.substr(0, pos);
    cout << email_name << endl;
}

void test08(){
    //string& insert(int pos, const char* s); //插入字符串 
    string s1 = "hello";
    s1.insert(1, "cool");
    cout << s1 << endl;

    //删除
    s1.erase(1, 4);
    cout << s1 << endl;
}

void test09(){
    string s = "abc";
    //string--> char *
    const char *p = s.c_str();
    cout << p << endl;

    //const char * --> string

    string s2 = p;

    cout << "s2 = " << s2 << endl;

}

void test10(){
    string s = "abcdefg";
    char &a = s[2];
    char &b = s[3];

    a = '1';
    b = '2';
    cout << s << endl; //确实改了

    cout << (int*)s.c_str() << endl;

    //重新分配内存
    s = "ppppppppppppp";
    a = '2';
    b = '3';
    cout << s << endl;
    cout << (int*)s.c_str() << endl; //并没有分配多的内存
}

//写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母
void test11(){
    string s = "abSSLAFJASaflsafasj";
    for(int i = 0; i < s.size(); ++i){
        s[i] = toupper(s[i]);
    }
    cout << s << endl;
}




int main(int argc, char *argv[]){ 
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    // test09();
    // test10();
    test11();

    return 0;
}
