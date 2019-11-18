/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-14 10:21:19
 */
#include <iostream>
using namespace std;

class CDocument{
public:
    void OnFileOpen(){
        //这是一个算法, 每个cout代表一个实际动作
        cout << "dialog..." << endl;
        cout << "check file..." << endl;
        cout << "open file..." << endl;
        Serialize();
        cout << "close file..." << endl;
        cout << "updata all views..." << endl;
    }

    virtual void Serialize() {}; //实现, 但里面没实际动作
};

class CMyDoc : public CDocument{
public:
    virtual void Serialize(){
        //只有对应的应用程序知道怎么序列化文件
        cout << "CMyDoc::Serialize()" << endl;
    }
};

int main(){
    CMyDoc myDoc; //对应要打开的文件
    myDoc.OnFileOpen();

    return 0;
}