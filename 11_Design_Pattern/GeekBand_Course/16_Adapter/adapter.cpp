/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-06 11:01:11
 */
//目标接口(新接口)
class ITarget
{
public:
    virtual void process() = 0;
};

//遗留接口(老接口)
class IAdaptee
{
public:
    virtual void foo(int data) = 0;
    virtual void bar() = 0;
};

//遗留类型
class OldClass : public IAdaptee
{
    //...
};

class Adapter : public ITarget
{
    IAdaptee *p_adaptee;

public:
    Adapter(IAdaptee *i_ad) : p_adaptee(i_ad) {}
    virtual void process() override
    {
        p_adaptee->bar();
        p_adaptee->foo(10);
    }
};

int main(int argc, char const *argv[])
{
    IAdaptee *pAdaptee = new OldClass;
    ITarget* pTarget = new Adapter(pAdaptee);
    pTarget->process();
    return 0;
}
