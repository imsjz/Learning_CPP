/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-14 16:28:17
 */
#include <iostream>

using namespace std;

int a; //全局 :初始化为０

//类测试
class TestA{
public:
    void print(){
        cout << "c_ " << c_ << endl;
    }
    int c_;
};

TestA d;

void test01(){

    int b; //局部　不初始化，为随机值
    cout << "b = " << b << endl;

}
int main(int argc, char *argv[]){
    
    cout << "a = " << a << endl;
    test01();

    ///////////测试类
    TestA e;
    cout << "=======================" << endl;
    cout << "类" <<endl;
    cout << "全局类　d = " << d.c_ << endl;
    cout << "函数内类 e = " << e.c_ << endl;



    return 0;
}
