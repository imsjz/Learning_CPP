/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-20 10:46:04
 */
#include <iostream>

using namespace std;


class BaseException{
public:
    virtual void PrintError(){
        cout << "基类异常错误" << endl;
    }
};

class NullPointerException: public BaseException{
public:
    virtual void PrintError(){
        cout << "空指针===异常错误" << endl;
    }
};

class OutOfRangeException : public BaseException{
public:
    virtual void PrintError(){
        cout << "越界   异常错误" << endl;
    }
};

void DoWork(){
    
    // throw NullPointerException();
    throw OutOfRangeException();
}

void test01(){
    try{
        DoWork();
    }
    catch(BaseException &e){
        e.PrintError();
    }
}


int main(int argc, char *argv[]){
    test01();

    return 0;
}
