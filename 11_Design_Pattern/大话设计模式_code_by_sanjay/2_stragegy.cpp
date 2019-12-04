/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-04 14:03:40
 */
//需求: 给出单价和数量, 求出每种商品的费用
//后续会对商品进行打折
//还会有促销: 如满100-30等策略
#include <iostream>
#include <string>
using namespace std;

class CashSuper
{ //收费父类
public:
    virtual double AcceptCash(double money) = 0;
};

//正常收费子类
class CashNormal : public CashSuper
{
public:
    virtual double AcceptCash(double money) override
    {
        return money;
    }
};

//打折收费子类
class CashRebate : public CashSuper
{
public:
    double m_rebate_rate = 1.0; //打折率默认为1
    CashRebate(double rate) : m_rebate_rate(rate) {}
    virtual double AcceptCash(double money) override
    {
        return money * m_rebate_rate;
    }
};

//返利收费子类
class CashReturn : public CashSuper
{
public:
    double m_condition = 0;
    double m_return = 0;
    CashReturn(double condition, double money_return) : m_condition(condition), m_return(money_return) {}
    virtual double AcceptCash(double money) override
    {
        double result = money;
        if (money >= m_condition)
        {
            result -= m_return;
        }
        return result;
    }
};

//context类
class CashContext
{
public:
    CashSuper *m_cs = nullptr;
    CashContext(CashSuper *cs) : m_cs(cs)
    {
    }
    double GetResult(double money)
    {
        return m_cs->AcceptCash(money);
    }
};


//这里是暴露给客户端的接口
int main(int argc, char const *argv[])
{
    CashContext *cc = nullptr;
    cout << "请选择收费模式: 1. 正常收费\t2. 满300返100\t3.打8折" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cc = new CashContext(new CashNormal);
        break;
    
    case 2:
        cc = new CashContext(new CashReturn(300, 100));
        break;
    case 3:
        cc = new CashContext(new CashRebate(0.8));
        break;
    }
    cout << "输入物品单价和数量, 用空格分开: " << endl;
    int price, num;
    cin >> price >> num;
    double result = cc->GetResult(price * num);
    cout << "原价为: " << price * num << ", 经过打折后价格为： " << result << endl;

    return 0;
}
