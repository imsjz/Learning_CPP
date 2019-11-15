/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-12 16:38:19
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
class MyString: public string
{
    public:
        MyString():string(){cout << "空参数的构造函数" << endl;}
        //类型转换构造函数
        MyString(const string &str):string(str){cout << "类型转换构造函数" << endl;}
        MyString(const char *s):string(s){ cout << "参数为const char*的构造函数" << endl;}
        //复制构造函数
        MyString(MyString &mystr):string(mystr){ cout << "复制构造函数" << endl;}
        //运算符重载
        MyString operator()(int start, int end);

};
MyString MyString::operator()(int start, int end){
    cout << "重载()" << endl;
    return this->substr(start, end);
}

int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 )     return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
}
int main() {
    //s4为复制构造函数出来的
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    //参数为const char*的构造函数
    //类型转换构造函数
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3; //这里有个类型转换构造函数
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;    s1 = "ijkl-";//确实是构造函数
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;//类型转换构造函数
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";//类型转换构造函数
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}