/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 16:58:59
 */
class ISubject
{
public:
    virtual void process();
};

//Proxy的设计
class SubjectProxy : public ISubject
{

public:
    virtual void process()
    {
        //对RealSubject的一种间接访问 里面实现很复杂, 有的语言通过工具生成
        //....
    }
};

class ClientApp
{

    ISubject *subject;

public:
    ClientApp()
    {
        subject = new SubjectProxy();
    }

    void DoTask()
    {
        //...
        subject->process();

        //....
    }
};