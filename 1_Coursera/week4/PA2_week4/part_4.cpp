/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-26 16:30:42
 *
 *
 *  给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

    输入
    第一行：正整数a，长度不超过100

    第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个

    第三行：正整数b，长度不超过100

    保证输入不含多余的空格或其它字符

    输出
    一行：表达式“a o b”的值。

    补充说明：

    1. 减法结果有可能为负数

    2. 除法结果向下取整

    3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigInt{
    string values; //保存所有位的数字
    bool flag; //true为正数，false为负数，默认为正数
    //比较输入数字的大小
    inline int compare(string s1, string s2){
        if(s1.size() > s2.size())
            return 1;
        else if(s1.size() < s2.size())
            return -1;
        else
            return s1.compare(s2); //如果s1 == s2, 那么如果s1大于s2,返回的值大于0，s1=s2的话返回0， s1小于s2的话返回的值小于0
    }
public:
    BigInt():values("0"), flag(true){}
    BigInt(string str){
        values = str;
        flag = true;
    }
    string getValues();
    bool getFlag();
    void setValues(string s);
    void setFlag(bool b);
    //friend int compare(const BigInt &lhs, const BigInt &rhs); //比较两个value的大小，如果lhs>rhs,返回1；如果lhs < rhs,返回-1，如果lhs=rhs，返回0
    friend ostream& operator<<(ostream &os, const BigInt& bigInt);
    friend istream& operator>>(istream &is, BigInt &bigInt);
    BigInt operator+(const BigInt &rhs);
    BigInt operator-(const BigInt &rhs);
    BigInt operator*(const BigInt &rhs);
    BigInt operator/(const BigInt &rhs);
};

string BigInt::getValues(){
    return values;
}
bool BigInt::getFlag(){
    return flag;
}
void BigInt::setValues(string s){
    values = s;
}
void BigInt::setFlag(bool b){
    flag = b;
}
// int compare(const BigInt &lhs, const BigInt &rhs){
//     if(lhs.values.size() > rhs.values.size())
//         return 1;
//     else if(lhs.values.size() < rhs.values.size())
//         return -1;
//     else
//         return 0;
// }
ostream& operator<<(ostream &os, const BigInt &bigInt){
    if(!bigInt.flag){
        os << "-";
    }
    os << bigInt.values;
    return os;
}
istream& operator>>(istream &is, BigInt &bigInt){
    string str;
    is >> str;
    bigInt.values = str;
    bigInt.flag = true;
    return is;
}
//重载"+"运算符
BigInt BigInt::operator+(const BigInt &rhs){
    BigInt ret; //返回的结果
    //ret.setFlag(true); //两个正整数相加的结果肯定为正
    ret.flag = true;
    string lvalues(values), rvalues(rhs.values); //因为是成员函数，所以可以访问到私有成员变量
    //处理特殊情况，即为0时
    if(lvalues == "0"){
        ret.values = rvalues;
        return ret;
    }
    if(rvalues == "0"){
        ret.values = lvalues;
        return ret;
    }
    //比较两者的长度大小，然后将小的前面补0
    unsigned int i, lsize, rsize;
    lsize = lvalues.size();
    rsize = rvalues.size();
    if(lsize < rsize){
        //在lvalue前补0
        for(i = 0; i < (rsize - lsize); ++i)
            lvalues = "0" + lvalues;
    }
    else{
        for(i = 0; i < (lsize - rsize); ++i)
            rvalues = "0" + rvalues;
    }
    //处理本质情况
     int n1, n2 = 0; //n1代表当前位，n2代表进位
     lsize = lvalues.size();//重新获取长度
     string res = ""; //字符串结果初始为""
     reverse(lvalues.begin(), lvalues.end());//转置
     reverse(rvalues.begin(), rvalues.end());
     for(i = 0; i < lsize; ++i){
        //  n1 = (int(lvalues[i]) + int(rvalues[i]) + n2) % 10;
        //  n2 = (int(lvalues[i]) + int(rvalues[i]) + n2) / 10;
        n1 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) % 10; //上面直接用int是不行的，因为int(char) 得到的是char所对应的ascii码
        n2 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) / 10;
        res += char(n1 + '0'); //n1是数字，想要变成字符串的数字要加上'0'
     }
     if(n2 == 1)
        res += char(n2 + '0');

    //加法操作完毕，处理余下工作并返回相应结果
    reverse(res.begin(), res.end());
    ret.values = res;
    return ret;
}

//重载"-"运算符
BigInt BigInt::operator-(const BigInt &rhs){
    BigInt ret; //返回的结果
    string lvalues(values), rvalues(rhs.values);
    //处理特殊情况
    if(lvalues == "0"){
        ret.flag = false;
        ret.values = rvalues;
        return ret;
    }
    if(rvalues == "0"){
        ret.flag = true;
        ret.values = lvalues;
        return ret;
    }
    //调整lhs和rhs的长度
    unsigned int i, lsize, rsize;
    lsize = lvalues.size();
    rsize = rvalues.size();
    if(lsize < rsize){
        for(i = 0; i < rsize - lsize; ++i)
            lvalues = "0" + lvalues;
    }
    else{
        for(i = 0; i < lsize - rsize; ++i)
            rvalues = "0" + rvalues;
    }
    //调整lvalues和rvalues，使l大于r
    int t = lvalues.compare(rvalues); //如果t > 0,l > r; t=0, l=r; t < 0, l < r
    if(t > 0){
        //lvalues > rvalues
        ret.flag = true;
    }
    else if(t < 0){
        ret.flag = false;
        string tmp = lvalues;
        lvalues = rvalues;
        rvalues = tmp;
    }
    else{
        ret.flag = true;
        ret.values = "0";
        return ret;
    }
    //处理本质情况
    unsigned j;
    string res;
    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());
    for(i = 0; i < lvalues.size(); ++i){
        if(lvalues[i] < rvalues[i]){ //不足，向前借一位
            j = 1;
            while(lvalues[i+j] == '0'){
                lvalues[i+j] = '9';
                j++;
            }
            lvalues[i+j] -= 1; //借位之后要减1
            res = res + char(lvalues[i] + 10 - rvalues[i] + '0');
        }
        else
            res = res + char(lvalues[i] - rvalues[i] + '0');
    }
    reverse(res.begin(), res.end());
    res.erase(0, res.find_first_not_of('0')); //去掉前导0

    ret.values = res;
    return ret;
}

//重载"*"运算符
BigInt BigInt::operator*(const BigInt &rhs){
    BigInt ret;
    ret.flag = true; //两个正数相乘肯定是正数
    string lvalues(values), rvalues(rhs.values);
    //处理特殊情况
    if(lvalues == "0" || rvalues == "0"){
        ret.values = "0";
        return ret;
    }
    string tmp;
    //让lvalues的长度大于rvalues
    if(lvalues < rvalues){
        tmp = lvalues;
        lvalues = rvalues;
        rvalues = tmp;
    }
    //处理本质情况
    int i, j, n1, n2, n3, t;
    BigInt res, itmp;
    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());
    for(i = 0; i < rvalues.size(); ++i){  //乘法的话以小的分别乘大的
        tmp = "";//每次一开始tmp都为空
        n1 = n2 = n3 = 0;
        for(j = 0; j < i; ++j){
            tmp = "0" + tmp;
        }
        n3 = rvalues[i] - '0';
        for(j = 0; j < lvalues.size(); ++j){
            t = (n3 * (lvalues[j] - '0') + n2);
            n1 = t % 10;
            n2 = t / 10; //进位
            tmp += char(n1 + '0');
        }
        if(n2){
            tmp += char(n2 + '0');
        }
        reverse(tmp.begin(), tmp.end());
        itmp.values = tmp;
        res = res + itmp;
    }
    ret = res;
    return ret;
}
//重载"/"运算符
BigInt BigInt::operator/(const BigInt &rhs){
    BigInt ret;
    ret.flag = true; //两个正数的除法肯定是正数
    string lvalues(values), rvalues(rhs.values);
    string quotient = ""; //商
    //处理特殊情况
    if(lvalues == "0"){
        ret.values = "0";
        return ret;
    }
    if(rvalues == "0"){
        ret.values = "error";
        return ret;
    }
    //比较大小，如果lvalue小于rvalues则返回1，如果等于返回1，如果大于则做相应除法
    if(compare(lvalues, rvalues) < 0){
        ret.values = "0";
        return ret;
    }
    else if(compare(lvalues, rvalues) == 0){
        ret.values = "1";
        return ret;
    }
    //处理本质情况
    else{
        string tmp;
        int i;
        int lsize = lvalues.size();
        int rsize = rvalues.size();
        if(rsize > 1)//大于1才要加
            tmp.append(lvalues, 0, rsize - 1);
        for(i = rsize - 1; i < lsize; ++i){
            tmp = tmp + lvalues[i];
            //试商
            for(char c = '9'; c >= '0'; --c){
                BigInt t = (BigInt)rvalues * (BigInt)string(1, c);
                BigInt m = (BigInt)tmp - t;

                if(m.flag){
                    tmp = m.values;
                    quotient += c;
                    break;
                }
            }
        }
    }
    //去除商前的0
    quotient.erase(0, quotient.find_first_not_of('0'));
    ret.values = quotient;
    return ret;
}

int main(){
    //测试
    BigInt lhs, rhs, result;
    char op;
    cin >> lhs >> op >> rhs;
    switch(op){
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
        default: break;
    }
    cout << result << endl;
    return 0;
}