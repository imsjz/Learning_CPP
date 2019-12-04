/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-04 12:07:08
 */
//实现一个计算器程序, 输入两个数和运算符, 得到结果
//简单工厂模式
#include <iostream>
#include <string>
using namespace std;


//1.运算类
class Operation{
public:
    virtual double GetResult() = 0;

    double m_numberA;
    double m_numberB;
};


//2.继承类
class OperationAdd : public Operation{
public:
    virtual double GetResult() override{
        return m_numberA + m_numberB;
    }
};
class OperationSub : public Operation{
public:
    virtual double GetResult() override{
        return m_numberA - m_numberB;
    }
};
class OperationMul : public Operation{
public:
    virtual double GetResult() override{
        return m_numberA * m_numberB;
    }
};
class OperationDiv : public Operation{
public:
    virtual double GetResult() noexcept override {
        return m_numberA / m_numberB; //暂不考虑除数为0情况
    }
};


//2. 简单工厂类
class OperationFactory{
public:
    Operation* m_op = nullptr;
    Operation* CreateOperate(char op){
        switch(op){
            case '+':
                m_op = new OperationAdd;
                break;
            case '-':
                m_op = new OperationSub;
                break;
            case '*':
                m_op = new OperationMul;
                break;
            case '/':
                m_op = new OperationDiv;
                break;
        }
        return m_op;
    }
};

int main(int argc, char const *argv[])
{
    OperationFactory* op_factory = new OperationFactory; //工厂
    Operation* op = op_factory->CreateOperate('/');
    op->m_numberA = 2;
    op->m_numberB = 3;
    double result = op->GetResult();
    cout << result << endl;

    return 0;
}
