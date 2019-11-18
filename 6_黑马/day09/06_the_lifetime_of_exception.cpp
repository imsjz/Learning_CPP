/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-20 10:13:24
 */
#include <iostream>

using namespace std;


class MyException{
public:
    MyException(){
        cout << "默认构造函数" << endl;
    }
    MyException(const MyException &m_e){
        cout << "拷贝构造函数" << endl;
    }
    ~MyException(){
        cout << "析构函数       ===" << endl;
    }
};

void DoWork(){
    // throw MyException(); //这里调用默认构造函数
    // throw &MyException(); //在栈申请的对象, 还没被捕获到就释放了
    throw new MyException(); //堆中申请的
}

void test01(){
    try{
        DoWork();
    }
    // catch(MyException &e){ //捕获DoWork抛出的异常, 用拷贝构造函数复制一份 // 最好就是传引用
    catch(MyException *e){
        cout << "捕获异常" << endl; //先运行完catch块才释放异常变量

        //在堆中申请的需要自己delete
        delete e; //靠自觉释放
    }
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
