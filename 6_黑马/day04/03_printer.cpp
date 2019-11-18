/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 19:27:27
 */
#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
public:
    static Printer *getInstance()   //static 修饰的是函数,而非返回值
    {
        
        return p;
    }
    void printText(string text){
        cout << "打印内容" << text << endl;
        cout << "打印机使用次数" << ++i << endl;
        cout << "======================" << endl;
    }

private:
    Printer() {i=0;}
    Printer(const Printer &p) {}
    static Printer *p;
    int i;
};

Printer *Printer::p = new Printer;

void test01()
{

    
    Printer *p = Printer::getInstance();
    p->printText("入职报告");
    p->printText("离职报告");
    p->printText("提交代码");
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
