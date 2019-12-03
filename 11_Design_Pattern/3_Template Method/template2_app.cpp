/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 15:21:03
 */
//应用程序开发人员
class Application : public Library
{
protected:
    virtual bool Step2()
    {
        //... 子类重写实现
    }

    virtual void Step4()
    {
        //... 子类重写实现
    }
};

int main()
{
    Library *pLib = new Application();
    lib->Run();

    delete pLib;
}
}
