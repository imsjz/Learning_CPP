/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-16 15:01:51
 */
#include <iostream>

using namespace std;


class Calculator{
public:

    int GetResult(string op){
        if(op == "+"){
            return a_ + b_;
        }
        else if(op == "-"){
            return a_ - b_;
        }
        else
        {
            return 0;
        }
        
    }

    int a_;
    int b_;
};


void test01(){
    Calculator calculator;
    calculator.a_ = 10;
    calculator.b_ = 20;
    cout << calculator.GetResult("+") << endl;
    cout << calculator.GetResult("-") << endl;
}

/********************************
真正开发中, 有一个开发原则: 开闭原则
对扩展开放, 对修改关闭
********************************/

//利用多态实现计算器
class AbstractCalculator{
public:

    //下面这个函数返回0, 没什么意义
    // virtual int GetResult(){ return 0;}

    //用纯虚函数, 如果父类有了纯虚函数, 子类继承父类, 子类必须实现纯虚函数
    //如果父类中有了纯 虚函数, 这个父类就无法实例化对象了
    //这两个类有了纯虚函数, 通常又称为抽象类
    virtual int GetResult() = 0;


    int a_;
    int b_;
};

//加法
class AddCalculator: public AbstractCalculator{
public:
    int GetResult(){
        return a_ + b_;
    }
};
//减法

class SubCalculator: public AbstractCalculator{
public:
    int GetResult(){
        return a_ - b_;
    }
};

//乘法
class MultiplyCalculator: public AbstractCalculator{
public:
    int GetResult(){
        return a_ * b_;
    }
};

void test02(){
    AbstractCalculator *abc;
    //加法
    abc = new AddCalculator;
    abc->a_ = 10;
    abc->b_ = 20;
    cout << abc->GetResult() << endl;

    delete abc;

    abc = new SubCalculator;
    abc->a_ = 20;
    abc->b_ = 10;
    cout << abc->GetResult() << endl;

    delete abc;

    abc = new MultiplyCalculator;
    abc->a_ = 20;
    abc->b_ = 20;
    cout << abc->GetResult() << endl;

    // abc = new AbstractCalculator; //不行,纯虚函数

}

int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
