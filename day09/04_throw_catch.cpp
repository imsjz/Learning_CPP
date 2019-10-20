/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-19 21:13:37
 */
#include <iostream>

using namespace std;

//自定义异常类
class MyException{
public:
    void PrintError(){
        cout << "自定义异常类" << endl;
    }
};

class Person{
public:
    Person(){
        cout << "Person构造函数" << endl;
    }
    ~Person(){
        cout << "Person析构函数" << endl;
    }
};


int MyDivide(int a, int b){
    if(b == 0){
        // throw -1; 
        // throw 3.14; //抛出的double类型, 异常必须处理, 如果不处理, 程序就挂掉
        // throw 'a';

        //栈解旋unwinding
        //从try开始 到 throw抛出异常之前, 所有栈上的对象都会被释放, 这个过程称为栈解旋
        //构造和析构的顺序相反
        Person p1;
        Person p2;

        //抛出自定义异常
        throw MyException(); //匿名对象
    }
    return a / b;
}


void test01(){
    int a = 10;
    int b = 0;
    try{
        int ret = MyDivide(a, b);
        cout << "ret = " << ret << endl;
    }
    catch(int){
        cout << "int 类型异常捕获" << endl;
    } //捕获异常
    catch(double){
        //如果不想处理这个异常, 可以继续向上抛出
        throw;
        cout << "double 类型异常捕获" << endl;
    }
    catch(MyException e){ //这里是形参, 然后接收throw传来的匿名对象
        e.PrintError();
    }
    catch(...){
        cout << "其他类型异常捕获" << endl;
    }

}
int main(int argc, char *argv[]){
    try{
        test01();
    }
    catch(char){ //如果异常没有处理, 那么成员terminate函数会使程序中断
        cout << "main函数double异常捕获" << endl;
    }
    catch(...){
        cout << "main其他类型异常捕获" << endl;
    }

    return 0;
}
